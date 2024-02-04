#include "MyMath.h"

Vector2f zBuffer::ChangeScreenPos(const Vector3f& pos) {
	Vector2f result;

	Vector2f centerPos = { kWindowWidth / 2.0f, kWindowHeight / 2.0f };

	Vector2f orthoPos;
	orthoPos.x = pos.x - centerPos.x;
	orthoPos.y = pos.y - centerPos.y;

	result.x = (orthoPos.x / (1.0f + (pos.z * 0.1f))) + centerPos.x;
	result.y = (orthoPos.y / (1.0f + (pos.z * 0.1f))) + centerPos.y;

	return result;
}

Vector2f zBuffer::ChangeScreenSize(const Vector3f& pos, const Vector2f& size) {
	Vector2f result;

	result.x = size.x / (1.0f + (pos.z * 0.1f));
	result.y = size.y / (1.0f + (pos.z * 0.1f));

	return result;
}

bool Collider::CollisionCircleCirlce(const Vector2f& posA, float radiusA, const Vector2f& posB, float radiusB) {
	float length = Vector::CalculateLength(posA, posB);

	if (length <= radiusA + radiusB) {
		return true;
	}

	return false;
}
