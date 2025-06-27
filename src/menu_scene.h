#pragma once

#include "iscene.h"
#include "raylib.h"
#include "bird.h"
#include <vector>
#include "pipe.h"

class MenuScene : public IScene
{
public:
    // Implement the virtual functions from IScene
    void Start() override;
    void Update(float delta) override;
    void Draw() override;
    MenuScene();
    ~MenuScene() override; // Mark as override
private:
    Texture2D background;
    Texture2D ground;
    Bird bird;
    std::vector<std::unique_ptr<Pipe>> pipes;
};