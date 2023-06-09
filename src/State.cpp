using namespace std;
#include <iostream>
#include <memory>
#include "../include/Face.h"
#include "../include/State.h"
#include "../include/Sprite.h"
#include "../include/Sound.h"
#define INCLUDE_SDL
#include "../include/SDL_include.h"
#include "../include/Component.h"
#include "../include/GameObject.h"
#include "../include/Face.h"
using namespace std;

State::State()
{
    LoadAssets();
    music.Play();
}

void State::LoadAssets()
{
    music.Open("../audio/stageState.ogg");
    GameObject *bg = new GameObject();
    bg->AddComponent(new Sprite(*bg, "../img/ocean.jpg"));
    objectArray.emplace_back(bg);
}

State::~State()
{
    // for (auto it = objectArray.rbegin(); it != objectArray.rend(); ++it)
    // {
    //     (*it).RequestDelete();
    // }
    objectArray.clear();
}

void State::Update(float dt)
{
    Input();
    for (int i = 0; i < objectArray.size(); ++i)
    {
        objectArray[i]->Update(dt);
    }

    auto it = objectArray.begin();
    for (int i = objectArray.size() - 1; i >= 0; --i)
    {
        if (objectArray[i]->IsDead())
        {
            objectArray.erase(it + i);
        }
    }
}

void State::Input()
{
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event))
    {

        // Se o evento for quit, setar a flag para terminação
        if (event.type == SDL_QUIT)
        {
            quitRequested = true;
        }

        // Se o evento for clique...
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for (int i = objectArray.size() - 1; i >= 0; --i)
            {
                // Obtem o ponteiro e casta pra Face.
                GameObject *go = (GameObject *)objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if (go->box.Contains({(float)mouseX, (float)mouseY}))
                {
                    Face *face = (Face *)go->GetComponent("Face");
                    if (nullptr != face)
                    {
                        // Aplica dano
                        face->Damage(std::rand() % 10 + 10);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_KEYDOWN)
        {
            // Se a tecla for ESC, setar a flag de quit
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quitRequested = true;
            }
            // if (event.key.keysym.sym == SDLK_d)
            // {
            //     for (auto &component : objectArray)
            //     {
            //         component->RequestDelete();
            //         objectArray.clear();
            //     }
            // }
            // Se não, crie um objeto
            else
            {
                Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
                AddObject((int)objPos.x, (int)objPos.y);
            }
        }
    }
}

void State::AddObject(int mouseX, int mouseY)
{
    auto obj = new GameObject{};
    auto sprite = new Sprite{*obj, "../img/penguinface.png"};
    obj->AddComponent(sprite);
    obj->box.x = mouseX - (sprite->GetWidth() / 2);
    obj->box.y = mouseY - (sprite->GetHeight() / 2);
    obj->box.w = sprite->GetWidth();
    obj->box.h = sprite->GetHeight();

    obj->AddComponent(new Sound(*obj, "../audio/boom.wav"));

    obj->AddComponent(new Face(*obj));

    objectArray.emplace_back(obj);
}

void State::Render()
{
    for (auto &component : objectArray)
    {
        component->Render();
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}