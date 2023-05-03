#include "../include/Face.h"
#include "../include/SDL_include.h"
#include "../include/GameObject.h"
#include "../include/Component.h"

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
}

void Face::Damage(int damage)
{
    hitpoints -= damage;
    if (hitpoints <= 0)
    {
        associated.RequestDelete();
        Component *sound = associated.GetComponent("Sound");
        if (sound != nullptr)
            sound->Play();
    }
}

void Face::Update(float dt) {}
void Face::Render() {}
bool Face::Is(string type)
{
    if (type != "Face")
        return false;
    return true;
}