#include "igameobject.h"
#include "id_manager.h"
#include <iostream>
IGameObject::IGameObject()
{
    id = IdManager::getInstance().generateId(); // Get ID from manager
    std::cout << "GameObject (ID: " << id << ") is generate." << std::endl;
}

IGameObject::~IGameObject()
{
    // Notify the IdManager that this ID is now free
    IdManager::getInstance().returnId(id);
    std::cout << "GameObject (ID: " << id << ") is being destroyed." << std::endl;
}

void IGameObject::Start()
{
}

void IGameObject::Update(float delta)
{
}

void IGameObject::Draw()
{
}
