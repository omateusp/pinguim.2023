#pragma once
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <string>
#include "Component.h"
#include "Vec2.h"

class Sprite : virtual public Component
{
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;
    Vec2 scale;

public:
    Sprite(GameObject &associated);
    Sprite(GameObject &associated, string file);
    Sprite(GameObject &associated, string file, int scaleX, int scaleY);
    ~Sprite();

    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(float x, float y);
    int GetWidth();
    int GetHeight();
    float GetXScale();
    float GetYScale();
    bool IsOpen();

    void Update(float dt);
    void Render();
    bool Is(string type);
    void Play();
    void SetScale(float scaleX, float scaleY);
};