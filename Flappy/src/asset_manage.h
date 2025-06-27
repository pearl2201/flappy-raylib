#pragma once  

#include <cstdint>  
#include <queue> // For a pool of free IDs  
#include <mutex> // For thread safety  
#include <raylib.h>  
#include <array> // Include array header  

class AssetManager {  
public:  
    static AssetManager& getInstance();  

    AssetManager(const AssetManager&) = delete;  
    AssetManager& operator=(const AssetManager&) = delete;  

    std::array<Texture2D, 3> birds{}; // Use Texture2D instead of Texture  
    Texture2D background{};
    Texture2D ground{};
    Texture pipeUpTexture{};
    Texture pipeDownTexture{};
    Texture btnPlay{};
    Texture logo{};
    Texture btnLeaderboard{};
    Texture labelScore{};
    Texture panelScoreBoard{};
    Texture labelTut {};
    Texture labelGameOver{};
    Texture labelGetReady{};

    void Load();

private:  
    AssetManager();  
    ~AssetManager();  
};