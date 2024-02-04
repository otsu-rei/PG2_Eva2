#include "SceneManager.h"

SceneManager::SceneManager() {
	CreateScene();

	sceneNo_ = SCENE_TITLE;
	sceneArr_[SCENE_TITLE]->Init();
}

void SceneManager::Run() {

	preSceneNo_ = sceneNo_;
	sceneNo_ = sceneArr_[sceneNo_]->GetSceneNum();

	if (sceneNo_ != preSceneNo_) {
		sceneArr_[preSceneNo_]->Finalize();

		sceneArr_[sceneNo_]->Init();
	}

	sceneArr_[sceneNo_]->Update();
	sceneArr_[sceneNo_]->Draw();
}

void SceneManager::CreateScene() {
	sceneArr_[SCENE_TITLE]  = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_GAME]   = std::make_unique<Scene_Game>();
	sceneArr_[SCENE_CLEAR]  = std::make_unique<Scene_Clear>();
}
