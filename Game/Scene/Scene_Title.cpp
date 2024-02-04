#include "Scene_Title.h"

#include "InputManager.h"
#include "Environment.h"

Scene_Title::Scene_Title() {
}

void Scene_Title::Init() {
}

void Scene_Title::Update() {
	if (InputManager::IsTriggerKeys(DIK_ESCAPE)) {
		isExitGame_ = true;
	}

	if (InputManager::IsTriggerKeys(DIK_SPACE)) {
		sceneNum_ = SCENE_GAME;
	}
}

void Scene_Title::Draw() {
	Novice::DrawBox(
		0, 0,
		kWindowWidth, kWindowHeight,
		0.0f,
		0x0A0A0AFF,
		kFillModeSolid
	);

	Novice::DrawSprite(
		0, 0,
		GameTextureManager::GetHandle("title"),
		1.0f, 
		1.0f,
		0.0f,
		0xFFFFFFFF
	);
}

void Scene_Title::Finalize() {
}