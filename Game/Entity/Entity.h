#pragma once

#include "MyVector3.h"
#include "MyVector2.h"

class Entity {
protected:

	Vector3f pos_;
	Vector2f size_;

	bool isAlive_;

	float radius_;

	Vector3f velocity_;

public:

	void Clamp();

	Vector3f GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

	bool GetIsAlive() const { return isAlive_; }
	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
};