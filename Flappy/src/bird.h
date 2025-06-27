#pragma once
#include <array>
#include "iscene.h"
#include "raylib.h"
#include "igameobject.h"

class Bird : public IGameObject
{
public:
	// Implement the virtual functions from IScene
	void Start() override;
	void Update(float delta) override;
	void Draw() override;
	Bird();
	~Bird() override; // Mark as override
private:
	std::array<Texture, 3> images;
	Vector2 position;
	float rotation;
	float scale;
	float imageFrameDuration;
	float imageFrameCooldown;
	int currentFrame;
	float vel;

};