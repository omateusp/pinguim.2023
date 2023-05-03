#include "../include/GameObject.h"
#include "../include/Component.h"
#include <iostream>

GameObject::GameObject()
{
}
GameObject::~GameObject()
{
    components.clear();
}

void GameObject::Update(float dt)
{
    for (auto &component : components)
    {

        component->Update(dt);
    }
}
void GameObject::Render()
{
    for (auto &component : components)
    {
        component->Render();
    }
}
bool GameObject::IsDead()
{
    return isDead;
}
void GameObject::RequestDelete()
{
    isDead = true;
    cout << "Should be dead" << endl;
}
void GameObject::AddComponent(Component *cpt)
{
    components.emplace_back(cpt);
}
void GameObject::RemoveComponent(Component *cpt)
{
    for (auto it : components)
    {
        if (it == cpt)
            delete it;
    }
}
Component *GameObject::GetComponent(string type)
{
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i]->Is(type))
        {
            return components.at(i);
        }
    }
    return nullptr;
}