#pragma once
#include <array>
#include "iscene.h"
#include "raylib.h"
#include "igameobject.h"
#include "bird.h"

class Pipe : public IGameObject
{
public:
    // Implement the virtual functions from IScene
    void Start() override;
    void Update(float delta) override;
    void Draw() override;
    bool CheckCollide(Bird bird);
    Pipe(Vector2 position);
    ~Pipe() override; // Mark as override
private:
    Texture pipeUpTexture;
    Texture pipeDownTexture;
    Vector2 position;
    float gap;
};