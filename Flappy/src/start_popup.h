#pragma once
#include <array>
#include "iscene.h"
#include "raylib.h"
#include "igameobject.h"
#include <functional>

class StartPopup: public IGameObject {
public:
    StartPopup(std::function<void()> onDeathCallback); // constructor

    void Update(float delta) override;
    void Draw() override;

private:
    std::function<void()> onDeath;
};