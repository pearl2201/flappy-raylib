#include "bird.h"
#include "iostream"
#include "menu_scene.h"
#include "raylib.h"
#include "settings.h"
#include "asset_manage.h"
MenuScene::MenuScene() : background(AssetManager::getInstance().background), ground(AssetManager::getInstance().ground), startPopup([this]() { OnClickPlay(); }) // Pass lambda callback
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
		//if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		//{
		//	gameState = GameState::Play;
		//}
		startPopup.Update(delta);
	}
	else if (gameState == GameState::Play)
	{
		for (const auto& i : gameObjects)
			i->Update(delta);
		for (const auto& i : pipes)
		{
			bool isCollide = i->CheckCollide(bird);
			if (isCollide)
			{
				std::cout << "end game";
				gameState = GameState::End;
				break;
			}
		}
		if (bird.IsDeath())
		{
			std::cout << "end game";
			gameState = GameState::End;
		}
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
	if (gameState == GameState::Start)
	{
		startPopup.Draw();
	}
	else if (gameState == GameState::Play)
	{

		// DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		for (const auto& i : gameObjects)
			i->Draw();
	}
	else
	{

	}



	DrawTextureEx(ground, Vector2{ 0, 587 }, 0.0f, 1.1, WHITE);
	EndDrawing();
}

void MenuScene::OnClickPlay()
{
	gameState = GameState::Play;
}

void MenuScene::OnClickLeaderboard()
{
}
