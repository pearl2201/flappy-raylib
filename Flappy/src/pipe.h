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
    bool CheckCollide(const Bird& bird);
    Pipe(Vector2 position);
    ~Pipe() override; // Mark as override
private:
    Texture2D pipeUpTexture;
    Texture2D pipeDownTexture;
    Vector2 position;
    float gap;
    Rectangle collider;
};