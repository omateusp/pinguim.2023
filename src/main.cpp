using namespace std;
#include "../include/Game.h"
// #include "Game.cpp"
// #include "Sprite.h"

int main(int argc, char **argv)
{
    Game &game = Game::GetInstance();
    game.Run();

    return 0;
}