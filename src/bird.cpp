#include "bird.h"
#include "raylib.h"
#include <iostream>
#include "settings.h"

Bird::Bird() : IGameObject()
{
}

Bird::~Bird()
{
}

void Bird::Start()
{
    images = {
        LoadTexture("./assets/image/bluebird-downflap.png"),
        LoadTexture("./assets/image/bluebird-midflap.png"),
        LoadTexture("./assets/image/bluebird-upflap.png"),
    };
    position = {60, GAME_VIEWPORT_CENTER};
    scale = 1;
    rotation = 0;
    imageFrameCooldown = 0;
    imageFrameDuration = 0.3;
    currentFrame = 0;
}

void Bird::Update(float deltaTime)
{
    imageFrameCooldown += deltaTime;
    if (imageFrameCooldown >= imageFrameDuration)
    {
        imageFrameCooldown -= imageFrameDuration;
        currentFrame = (currentFrame + 1) % 3;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        vel = BIRD_Y_ACC;
    }

    vel += GRAVITY * deltaTime;
    position.y += vel * deltaTime;
    if (position.y > SCENE_GROUND)
    {
        position.y = SCENE_GROUND;
    }
}

void Bird::Draw()
{
    auto x = Vector2{position};
    x.x = x.x - images[0].width / 2;
    x.y = x.y - images[0].height / 2;
    DrawTextureEx(images[currentFrame], x, rotation, scale, WHITE);
}