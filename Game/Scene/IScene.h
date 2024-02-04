#pragma once

////////////////////////////////////////////////////////////////////////////////////////////
// SceneType Enum
////////////////////////////////////////////////////////////////////////////////////////////
enum SceneType {
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_CLEAR,

	COUNT_SCENE
};

////////////////////////////////////////////////////////////////////////////////////////////
// IScene class
////////////////////////////////////////////////////////////////////////////////////////////
class IScene {
protected:

	//=========================================================================================
	// protected variables
	//=========================================================================================

	static int sceneNum_;
	static bool isExitGame_;

public:

	//=========================================================================================
	// public methods
	//=========================================================================================

	// destructor
	virtual	~IScene();

	// default method
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;

	// accessor
	int GetSceneNum() { return sceneNum_; }
	static bool GetIsExitGame() { return isExitGame_; }

};

