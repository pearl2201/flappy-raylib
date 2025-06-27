#include "menu_scene.h"
#include "raylib.h"
#include "bird.h"
#include "settings.h"
#include "iostream"
MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
    pipes.clear();
}

void MenuScene::Start()
{
    background = LoadTexture("./assets/image/background-day.png");
    ground = LoadTexture("./assets/image/ground.png");
    bird = Bird();

    bird.Start();

    for (int i = 0; i < PIPE_COUNT; i++)
    {
        auto pipe = Pipe(Vector2(START_PIPE_POS + i * DISTANCE_BETWEEN_PIPE, GAME_VIEWPORT_CENTER));
        AddGameObject(std::make_unique<Pipe>(pipe));
        pipes.push_back(std::move(std::make_unique<Pipe>(pipe)));
    }
    AddGameObject(std::make_unique<Bird>(bird));
    SetTargetFPS(30);
}

void MenuScene::Update(float delta)
{
    for (const auto &i : gameObjects)
        i->Update(delta);
}

void MenuScene::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 720.0 / 512, WHITE);

    // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    for (const auto &i : gameObjects)
        i->Draw();
    DrawTextureEx(ground, (Vector2){0, 587}, 0.0f, 1.1, WHITE);
    EndDrawing();
}