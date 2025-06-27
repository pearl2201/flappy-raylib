#include "iscene.h"
#include "igameobject.h"
#include <memory>
#include "vector"
#include <algorithm>

void IScene::AddGameObject(std::unique_ptr<IGameObject> gameObject)
{
     std::lock_guard<std::mutex> lock(m_mutex);
    gameObjects.push_back(std::move(gameObject));
}

void IScene::RemoveGameObject(std::unique_ptr<IGameObject> gameObject)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](std::unique_ptr<IGameObject> &obj)
                           { return obj->id == gameObject->id; });

    if (it != gameObjects.end())
    {
        auto retval = std::move(*it);
        gameObjects.erase(it);
    }
}
// void IScene::RemoveGameObject(std::unique_ptr<IGameObject> gameObject)
// {
// std::vector<unique_ptr<Object>>::iterator object =
//         find_if(objects.begin(), objects.end(),
//                 [&](unique_ptr<Object> & obj){ return obj->name() == objName;}
//                );
//     objects.erase(std::remove(objects.begin(), objects.end(), *object));
//     return std::move(*object);
// }