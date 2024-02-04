#pragma once

#include <list>

#include "MyMath.h"
#include "DrawMethod.h"

#include "MyVector2.h"
#include "MyVector3.h"

class Bullet {
protected:

	struct Object {
		Vector3f pos;
		Vector3f velocity;
	};

	Vector2f size_;
	float radius_;
	float hitDepthRange_;

	std::list<Object> bullets_;

public:

	std::list<Object>& GetBullet() { return bullets_; }

	float GetHitDepthRange() const { return hitDepthRange_; }
	float GetRadius() const { return radius_; }

};