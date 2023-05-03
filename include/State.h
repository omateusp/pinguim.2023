#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Sprite.h"
#include "Music.h"

class State
{
private:
    vector<unique_ptr<GameObject>> objectArray;
    Music music;

    bool quitRequested = false;

    void Input();
    void AddObject(int mouseX, int mouseY);

public:
    State();
    ~State();

    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};