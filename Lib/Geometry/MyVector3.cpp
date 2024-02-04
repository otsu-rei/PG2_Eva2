#include "MyVector3.h"

Vector3f Vector::CalculateDirection(const Vector3f& posA, const Vector3f& posB) {
	return posB - posA;
}

float Vector::CalculateLength(const Vector3f& posA, const Vector3f& posB) {
	return std::sqrtf((posB.x - posA.x) * (posB.x - posA.x) + (posB.y - posA.y) * (posB.y - posA.y) + (posB.z - posA.z) * (posB.z - posA.z));
}

float Vector::DotProduct(const Vector3f& vectorA, const Vector3f& vectorB) {
	return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}

Vector3f Vector::CrossProduct(const Vector3f& vectorA, const Vector3f& vectorB) {
	Vector3f result = {
	vectorA.y * vectorB.z - vectorA.z * vectorB.y, // x
	vectorA.z * vectorB.x - vectorA.x * vectorB.z, // y
	vectorA.x * vectorB.y - vectorA.y * vectorB.x, // z
	};

	return result;
}

void Vector::Normalize(Vector3f& vector) {
	float length = Vector::CalculateLength(vector, { 0.0f });

	/*assert(length != 0.0f);*/

	if (length != 0.0f) {
		vector.x /= length;
		vector.y /= length;
		vector.z /= length;
	}
}
