#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#include "IScene.h"
#include "SafeDelete.h"

#include "DrawMethod.h"

#include "Player.h"
#include "Enemy.h"

#include "CollisionManager.h"

////////////////////////////////////////////////////////////////////////////////////////////
// Scene_Game class
////////////////////////////////////////////////////////////////////////////////////////////
class Scene_Game
	: public IScene {
public:

	//=========================================================================================
	// public methods
	//=========================================================================================
	Scene_Game();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	Player* player_;

	static const int kMaxEnemyNum_ = 5;
	Enemy* enemy_[kMaxEnemyNum_];
};