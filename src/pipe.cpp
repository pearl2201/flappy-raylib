#include "pipe.h"
#include "raylib.h"
#include <iostream>
#include "settings.h"

Pipe::Pipe(Vector2 position) : IGameObject()
{
    this->position = position;
    pipeUpTexture = LoadTexture("./assets/image/pipe-green.png");
    pipeDownTexture = LoadTexture("./assets/image/pipe-green-1.png");
}

Pipe::~Pipe()
{
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

    DrawTexture(pipeUpTexture, position.x + pipeUpTexture.width / 2, position.y + PIPE_DISTANCE / 2, WHITE);
    DrawTexture(pipeDownTexture, position.x + pipeDownTexture.width / 2, position.y - PIPE_DISTANCE / 2 - pipeDownTexture.height, WHITE);
}