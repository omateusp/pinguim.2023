#pragma once
#include <string>
using namespace std;

class GameObject;

class Component
{
public:
    Component(GameObject &associated);
    virtual ~Component() = 0;

    void virtual Update(float dt) = 0;
    void virtual Render() = 0;
    bool virtual Is(string type) = 0;

    void virtual Play() = 0;

protected:
    GameObject &associated;
};