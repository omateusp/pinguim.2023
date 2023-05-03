#pragma once
#include <string>
#include "SDL2/SDL_mixer.h"

class Music
{
private:
    Mix_Music *music;

public:
    Music();
    Music(string file);

    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(string file);
    bool IsOpen();
};