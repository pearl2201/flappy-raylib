#pragma once

#include "vector"
#include "igameobject.h"
class IScene
{
public:
    virtual ~IScene() = default;
    virtual void Start() = 0;
    virtual void Update(float delta) = 0;
    virtual void Draw() = 0;
    void AddGameObject(std::unique_ptr<IGameObject> gameObject);
    void RemoveGameObject(std::unique_ptr<IGameObject> gameObject);

protected:
    std::vector<std::unique_ptr<IGameObject>> gameObjects;
    std::mutex m_mutex; // Protects m_nextId and m_freeIds
};