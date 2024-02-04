#pragma once

#include "Environment.h"
#include "MyVector2.h"
#include "MyVector3.h"

namespace zBuffer {
	Vector2f ChangeScreenPos(const Vector3f& pos);
	Vector2f ChangeScreenSize(const Vector3f& pos, const Vector2f& size);
}

namespace Collider {
	bool CollisionCircleCirlce(const Vector2f& posA, float radiusA, const Vector2f& posB, float radiusB);
}
