#include "Scene_Clear.h"

#include "InputManager.h"
#include "Environment.h"

Scene_Clear::Scene_Clear() {
}

void Scene_Clear::Init() {
}

void Scene_Clear::Update() {
	if (InputManager::IsTriggerKeys(DIK_SPACE)) {
		sceneNum_ = SCENE_TITLE;
	}
}

void Scene_Clear::Draw() {
	Novice::DrawBox(
		0, 0,
		kWindowWidth, kWindowHeight,
		0.0f,
		0x0A0A0AFF,
		kFillModeSolid
	);

	Novice::ScreenPrintf(kWindowWidth / 2, kWindowHeight / 2, "Game Clear");
}

void Scene_Clear::Finalize() {
}