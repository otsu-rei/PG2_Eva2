#include "MyVector2.h"

float Vector::CalculateLength(const Vector2f& posA, const Vector2f& posB) {
	return std::sqrtf((posB.x - posA.x) * (posB.x - posA.x) + (posB.y - posA.y) * (posB.y - posA.y));
}
