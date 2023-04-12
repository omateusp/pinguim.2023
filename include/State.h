#include <string>
#include "Sprite.h"
#include "Music.h"

class State
{
private:
    Sprite bg;
    Music music;
    bool quitRequested = false;

public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};