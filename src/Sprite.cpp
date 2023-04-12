using namespace std;
#include <iostream>
#include "../include/Sprite.h"
#include <string>
#include "../include/Game.h"
#define INCLUDE_SDL
#include "../include/SDL_include.h"

Sprite::Sprite()
{
    texture = nullptr;
}

Sprite::Sprite(string file)
{
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

// TODO: Tratar erro texture == nullptr
void Sprite::Open(string file)
{
    Game &game = Game::GetInstance();
    texture = IMG_LoadTexture(game.GetRenderer(), file.c_str());
    if (texture == nullptr)
    {
        cout << "Could not load texture" << file << endl;
        return;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(150, 50, width, height);
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

void Sprite::Render(int x, int y)
{
    if (texture == nullptr)
    {
        cout << "No texture found!" << endl;
        return;
    }
    Game &game = Game::GetInstance();
    SDL_Rect dest{x, y, width, height};
    SDL_RenderCopy(game.GetRenderer(), texture, nullptr, &dest);
}