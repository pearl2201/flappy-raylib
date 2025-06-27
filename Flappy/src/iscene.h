#pragma once

#include "vector"
#include "igameobject.h"
#include <mutex>
class IScene
{
public:
    virtual ~IScene() = default;
    virtual void Start() = 0;
    virtual void Update(float delta) = 0;
    virtual void Draw() = 0;
    void AddGameObject(std::shared_ptr<IGameObject> gameObject);
    void RemoveGameObject(std::shared_ptr<IGameObject> gameObject);

protected:
    std::vector<std::shared_ptr<IGameObject>> gameObjects;
    std::mutex m_mutex; // Protects m_nextId and m_freeIds
};