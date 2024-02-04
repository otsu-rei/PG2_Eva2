#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#define _USE_MATH_DEFINES
#include <cmath>
#include "Entity.h"

#include "Json.h"
#include "Random.h"
#include "DrawMethod.h"
#include "MyMath.h"

class Enemy
	: public Entity {
public:

	//=========================================================================================
	// public methods
	//=========================================================================================
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw();
	void Finalize();

	static int GetDestroyNum() { return destroyNum_; }

	//=========================================================================================
	// public variables
	//=========================================================================================

private:

	//=========================================================================================
	// private methods
	//=========================================================================================
	void LoadJson();

	void Move();

	void Rotate();

	void Respown();

	//=========================================================================================
	// private variables
	//=========================================================================================
	struct RangeVector3f {
		Vector3f min;
		Vector3f max;
	};

	RangeVector3f randomPos_;
	RangeVector3f randomVelocity_;

	float theta_;
	int radian_;

	float respownTime_;
	float respownCount_;

	static const std::string jsonPath_;

	static int destroyNum_;
};