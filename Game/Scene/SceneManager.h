#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#include <memory>

// scene ---
#include "IScene.h"
#include "Scene_Title.h"
#include "Scene_Game.h"
#include "Scene_Clear.h"

////////////////////////////////////////////////////////////////////////////////////////////
// SceneManager
////////////////////////////////////////////////////////////////////////////////////////////
class SceneManager {
public:

	//=========================================================================================
	// public methods
	//=========================================================================================

	SceneManager();

	void Run();

private:

	//=========================================================================================
	// private variables
	//=========================================================================================

	std::unique_ptr<IScene> sceneArr_[SceneType::COUNT_SCENE];

	int sceneNo_;
	int preSceneNo_;

	//=========================================================================================
	// private methods
	//=========================================================================================

	void CreateScene();
};