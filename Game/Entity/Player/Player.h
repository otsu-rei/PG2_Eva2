#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#define _USE_MATH_DEFINES
#include <cmath>

#include "Entity.h"
#include <ImGui.h>

#include <string>
#include "SafeDelete.h"
#include "DrawMethod.h"

#include "MyMath.h"

#include "MyVector3.h"
#include "MyVector2.h"

#include "PlayerBullet.h"
#include "Cursor.h"


////////////////////////////////////////////////////////////////////////////////////////////
// Player class
////////////////////////////////////////////////////////////////////////////////////////////
class Player
	: public Entity {
public: // menber methods //

	// constructor & destructor
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	void Finalize();

	void ImGui();

private: // menber objects //

	float speed_;

	std::string jsonPath_ = "player/player.json";

	PlayerBullet* bullet_;
	Cursor* cursor_;

private: // user methods //

	void LoadJson();

	void UpdateBullet();

public: // accessor //

	PlayerBullet* GetBullet() const { return bullet_; }

};