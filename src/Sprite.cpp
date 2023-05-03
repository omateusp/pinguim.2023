using namespace std;
#include <iostream>
#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/Sprite.h"
#include "../include/Component.h"
#include <string>
#define INCLUDE_SDL
#include "../include/SDL_include.h"

Sprite::Sprite(GameObject &associated) : Component(associated), scale(1, 1)
{
    texture = nullptr;
}

Sprite::Sprite(GameObject &associated, string file) : Sprite(associated)
{
    Open(file);
}

Sprite::Sprite(GameObject &associated, string file, int scaleX, int scaleY) : Sprite(associated, file)
{
    SetScale(scaleX, scaleY);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

// TODO: Tratar erro texture == nullptr
void Sprite::Open(string file)
{
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (texture == nullptr)
    {
        cout << "Could not load texture" << file << endl;
        return;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
}

int Sprite::GetWidth()
{
    return width;
}

int Sprite::GetHeight()
{
    return height;
}

bool Sprite::IsOpen()
{
    if (texture == nullptr)
        return false;
    return true;
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    SDL_Rect clip{x, y, w, h};
    clipRect = clip;
}

void Sprite::Render(float x, float y)
{
    if (texture == nullptr)
    {
        cout << "No texture found!" << endl;
        return;
    }
    SDL_Rect dest{(int)x, (int)y, (int)(clipRect.w * scale.x), (int)(clipRect.h * scale.y)};
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dest);
}

void Sprite::Update(float dt) {}

void Sprite::Render()
{
    Render(associated.box.x, associated.box.y);
}

bool Sprite::Is(string type)
{
    if (type != "Sprite")
        return false;
    return true;
}
void Sprite::Play() {}

void Sprite::SetScale(float scaleX, float scaleY)
{
    scale.x = scaleX > 0 ? scaleX : 0.01;
    scale.y = scaleY > 0 ? scaleY : 0.01;
}

float Sprite::GetXScale()
{
    return scale.x;
}

float Sprite::GetYScale()
{
    return scale.y;
}