// src/IdManager.cpp
#include "asset_manage.h"
#include "id_manager.h"
#include <iostream>

void AssetManager::Load()
{
    birds = {
        LoadTexture("image/bluebird-downflap.png"),
        LoadTexture("image/bluebird-midflap.png"),
        LoadTexture("image/bluebird-upflap.png"),
    };
    background = LoadTexture("image/background-day.png");
    ground = LoadTexture("image/ground.png");

    pipeUpTexture = LoadTexture("image/pipe-green.png");
    pipeDownTexture = LoadTexture("image/pipe-green-1.png");
    btnPlay = LoadTexture("image/btn_play.png");
    logo = LoadTexture("image/logo.png");
    btnLeaderboard = LoadTexture("image/btn_leaderboard.png");
    labelScore = LoadTexture("image/score.png");
    panelScoreBoard = LoadTexture("image/score_board.png");
    labelTut = LoadTexture("image/tut.png");
    labelGameOver = LoadTexture("image/game_over.png");
    labelGetReady = LoadTexture("image/get_ready.png");
}

AssetManager::AssetManager()  {
    std::cout << "IdManager: Instance created." << std::endl;
}

AssetManager::~AssetManager()
{
    for (const auto& texture : birds)
    {
        UnloadTexture(texture);
    }
    UnloadTexture(background);
    UnloadTexture(ground);
    UnloadTexture(pipeUpTexture);
    UnloadTexture(pipeDownTexture);
}

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}
