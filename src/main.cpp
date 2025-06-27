#include "raylib.h"
#include "iscene.h"
#include "menu_scene.h"
#include <memory>
#include "settings.h"
int main(void)
{
    InitWindow(SCENE_WIDTH, SCENE_HEIGHT, "raylib [core] example - basic windo");
    std::unique_ptr<MenuScene> scene = std::make_unique<MenuScene>();
    scene->Start();
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        scene->Update(dt);
        scene->Draw();
    }

    CloseWindow();

    return 0;
}