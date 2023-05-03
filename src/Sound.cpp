#define INCLUDE_SDL_MIXER
#include "../include/SDL_include.h"
#include "../include/Sound.h"
#include "../include/GameObject.h"
#include "../include/Component.h"
#include <iostream>

Sound::Sound(GameObject &associated) : Component(associated) {}
Sound::Sound(GameObject &associated, string file) : Sound(associated)
{
    Open(file);
}
Sound::~Sound()
{
    Mix_FreeChunk(chunk);
}

void Sound::Play()
{
    Play(1);
}

void Sound::Play(int times)
{
    if (chunk == nullptr)
    {
        cout << "chunk is nullptr" << endl;
        return;
    }
    const int TEMP_CHANNEL = Mix_PlayChannel(-1, chunk, times - 1);
    if (TEMP_CHANNEL == -1)
    {
        cout << "Mix_PlayChannel: " << Mix_GetError() << endl;
        return;
    }
    channel = TEMP_CHANNEL;
}
void Sound::Stop()
{
    if (chunk != nullptr)
        Mix_HaltChannel(channel);
}
void Sound::Open(string file)
{
    chunk = Mix_LoadWAV(file.c_str());
    if (!chunk)
    {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
        // handle error
    }
}
bool Sound::IsOpen()
{
    if (chunk == nullptr)
        return false;
    return true;
}

void Sound::Update(float dt) {}
void Sound::Render() {}
bool Sound::Is(string type)
{
    if (type != "Sound")
        return false;
    return true;
}