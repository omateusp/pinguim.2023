using namespace std;
#include <iostream>
#include "../include/Game.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "../include/SDL_include.h"

Game *Game::instance;

Game &Game::GetInstance()
{
    if (instance != nullptr)
        return *instance;
    instance = new Game("Mateus Oliveira Patrício - 16/0015006", 1024, 600);
    return *instance;
}

inline void close4()
{
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

Game::Game(string title, int width, int height)
{
    // Checks that instance doesn't already exist
    if (instance != nullptr)
        instance = this;

    // SDL_Init
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
    {
        cout << "SDL_Init failed: " << SDL_GetError() << endl;
        SDL_Quit();
        throw std::runtime_error("SDL_Init failed");
    }

    // IMG_Init
    const int IMG_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    int img_initted = IMG_Init(IMG_FLAGS);
    if ((img_initted & IMG_FLAGS) != IMG_FLAGS)
    {
        cout << "IMG_Init: Failed to init required jpg, png and tif support!" << endl;
        cout << "IMG_Init: " << IMG_GetError() << endl;
        IMG_Quit();
        SDL_Quit();
        throw std::runtime_error("IMG_Init failed");
    }

    // MIX_Init
    const int MIX_FLAGS = MIX_INIT_OGG;
    int mix_initted = Mix_Init(MIX_FLAGS);
    if (mix_initted && MIX_FLAGS != MIX_FLAGS)
    {
        cout << "Mix_Init: Failed to init required ogg support!" << endl;
        cout << "Mix_Init: " << Mix_GetError() << endl;
        close4();
        throw std::runtime_error("Mix_Init failed");
    }
    int oAR = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    if (oAR != 0)
    {
        cout << "Mix_OpenAudio: Failed to open" << endl;
        cout << "Mix_OpenAudio: " << Mix_GetError() << endl;
        close4();
        throw std::runtime_error("Mix_OpenAudio failed");
    }
    Mix_AllocateChannels(32);
    char *window_name = &*title.begin();
    window = SDL_CreateWindow(window_name, 0, 0, width, height, 0); // SDL_WINDOWPOS_CENTERED
    if (window == nullptr)
    {
        close4();
        throw std::runtime_error("SDL_CreateWindow failed");
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        close4();
        throw std::runtime_error("SDL_CreateRenderer failed");
    }
    state = new State();
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    close4();
}

State &Game::GetState()
{
    return *state;
}

SDL_Renderer *Game::GetRenderer()
{
    return renderer;
}

void Game::Run()
{
    state->LoadAssets();
    while (!state->QuitRequested())
    {
        state->Update(1);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}