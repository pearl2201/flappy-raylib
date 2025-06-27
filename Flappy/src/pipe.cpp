#include "pipe.h"
#include "raylib.h"
#include <iostream>
#include "settings.h"
#include "asset_manage.h"

Pipe::Pipe(Vector2 position) : IGameObject()
{
    this->position = position;
    pipeUpTexture = AssetManager::getInstance().pipeUpTexture;
    pipeDownTexture = AssetManager::getInstance().pipeDownTexture;
    gap = GetRandomValue(PIPE_DISTANCE, PIPE_DISTANCE * 1.5f);
}

Pipe::~Pipe()
{
    std::cout << "Unload Pipe";
}

void Pipe::Start()
{
}

void Pipe::Update(float deltaTime)
{
    position.x -= PIPE_VELOCITY_X * deltaTime;
    if (position.x < -150)
    {
        position.x += RESET_PIPE_DISTANCE;
    }
}

void Pipe::Draw()
{
    // auto x = Vector2{position};
    // x.x = x.x - images[0].width / 2;
    // x.y = x.y - images[0].height / 2;
    // DrawTextureEx(images[currentFrame], x, rotation, scale, WHITE);

    DrawTexture(pipeUpTexture, position.x + pipeUpTexture.width / 2, position.y + gap / 2, WHITE);
    DrawTexture(pipeDownTexture, position.x + pipeDownTexture.width / 2, position.y - gap / 2 - pipeDownTexture.height, WHITE);
}

bool Pipe::CheckCollide(const Bird& bird)
{
    return false;
}


static bool IsAABBCollide(const Rectangle& a, const Rectangle& b)
{
    return (a.x < b.x + b.width &&
        a.x + a.width > b.x &&
        a.y < b.y + b.height &&
        a.y + a.height > b.y);
}