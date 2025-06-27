#include "start_popup.h"
#include "asset_manage.h"
#include "settings.h"

StartPopup::StartPopup(std::function<void()> onDeathCallback) : onDeath(onDeathCallback)
{
}

void StartPopup::Draw()
{
    Texture* texture = &(AssetManager::getInstance().logo);
    DrawTexture(*texture, SCENE_WIDTH / 2 - texture->width / 2, 100,WHITE);
    texture = &(AssetManager::getInstance().labelGetReady);
    DrawTexture(*texture, SCENE_WIDTH / 2 - texture->width / 2, 300, WHITE);
    texture = &(AssetManager::getInstance().btnPlay);
    DrawTexture(*texture, SCENE_WIDTH / 2 - texture->width / 2, 370, WHITE);
    texture = &(AssetManager::getInstance().labelTut);
    DrawTexture(*texture, SCENE_WIDTH / 2 - texture->width / 2, 450, WHITE);
}

void StartPopup::Update(float delta)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        onDeath();
    }
}
