using namespace std;
#include <iostream>
#include "../include/Music.h"
#include <string>
#define INCLUDE_SDL
#include "../include/SDL_include.h"

Music::Music()
{
    music = nullptr;
}

Music::Music(string file)
{
    music = nullptr;
    Open(file);
}

void Music::Play(int times)
{
    if (music == nullptr)
    {
        cout << "music is nullptr" << endl;
        return;
    }
    if (Mix_PlayingMusic())
        return;
    if (Mix_PlayMusic(music, times) == -1)
    {
        cout << "Mix_PlayMusic: " << Mix_GetError() << endl;
    }
}

void Music::Stop(int msToStop)
{
    while (!Mix_FadeOutMusic(msToStop) && Mix_PlayingMusic())
    {
        // wait for any fades to complete
        SDL_Delay(100);
    }
}

void Music::Open(string file)
{
    music = Mix_LoadMUS(file.c_str());
    if (!music)
    {
        cout << "Mix_LoadMUS(" << file << "): " << Mix_GetError() << endl;
        // this might be a critical error...
    }
}

bool Music::IsOpen()
{
    if (music == nullptr)
        return false;
    return true;
}