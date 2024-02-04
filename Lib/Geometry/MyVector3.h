#pragma once
#include <cmath>
#include <assert.h>

template <typename T>
class Vector3 {
public:
	T x, y, z;

	// operator overload //
	/* Add */
	Vector3 operator+(const Vector3& other) const {
		return { x + other.x, y + other.y, z + other.z };
	}
	void operator+=(const Vector3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
	}

	/* Subtract */
	Vector3 operator-(const Vector3& other) const {
		return { x - other.x, y - other.y, z - other.z };
	}
	void operator-=(const Vector3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	/* Multiply */
	Vector3 operator*(const Vector3& other) const {
		return { x * other.x, y * other.y, z * other.z };
	}
	void operator*=(const Vector3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
	}
	// scalar
	Vector3 operator*(T scalar) const {
		return { x * scalar, y * scalar, z * scalar };
	}
	void operator*=(T scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}
};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;

namespace Vector {
	Vector3f CalculateDirection(const Vector3f& posA, const Vector3f& posB);
	float CalculateLength(const Vector3f& posA, const Vector3f& posB);

	float DotProduct(const Vector3f& vectorA, const Vector3f& vectorB);
	Vector3f CrossProduct(const Vector3f& vectorA, const Vector3f& vectorB);


	void Normalize(Vector3f& vector);
}
