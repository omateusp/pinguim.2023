#pragma once
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"
#include <string>

class GameObject;

class Sound : public Component
{
private:
    Mix_Chunk *chunk;
    int channel;

public:
    Sound(GameObject &associated);
    Sound(GameObject &associated, string file);
    ~Sound();

    void Play();
    void Play(int times);
    void Stop();
    void Open(string file);
    bool IsOpen();

    void Update(float dt);
    void Render();
    bool Is(string type);
};