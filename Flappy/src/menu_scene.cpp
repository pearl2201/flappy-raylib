#include "bird.h"
#include "iostream"
#include "menu_scene.h"
#include "raylib.h"
#include "settings.h"
MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
	UnloadTexture(background);
	UnloadTexture(ground);
	pipes.clear();
}

void MenuScene::Start()
{
	background = LoadTexture("image/background-day.png");
	ground = LoadTexture("image/ground.png");

	bird.Start();

	for (int i = 0; i < PIPE_COUNT; i++)
	{
		float x = START_PIPE_POS + i * DISTANCE_BETWEEN_PIPE;
		float y = GAME_VIEWPORT_CENTER;
		auto pipe = std::make_shared<Pipe>(Vector2(x, y));

		AddGameObject(pipe);
		pipes.push_back(pipe);
	}
	AddGameObject(std::make_shared<Bird>(bird));
	SetTargetFPS(30);
}


void MenuScene::Update(float delta)
{
	if (gameState == GameState::Start)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			gameState = GameState::Play;
		}
	}
	else if (gameState == GameState::Play)
	{
		for (const auto& i : gameObjects)
			i->Update(delta);
	}
	else
	{

	}

}

void MenuScene::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawTextureEx(background, Vector2{ 0, 0 }, 0.0f, 720.0 / 512, WHITE);

	// DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	for (const auto& i : gameObjects)
		i->Draw();
	DrawTextureEx(ground, Vector2{ 0, 587 }, 0.0f, 1.1, WHITE);
	EndDrawing();
}