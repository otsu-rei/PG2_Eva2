#pragma once

#include <cmath>

template <typename Type>
class Vector2 {
public:
	Type x, y;

	// operator overload //
	/* Add */
	Vector2 operator+(const Vector2& other) const {
		return { x + other.x, y + other.y };
	}
	void operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
	}

	/* Subtruct */
	Vector2 operator-(const Vector2& other) const {
		return { x - other.x, y - other.y };
	}
	void operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
	}

	/* Multiply */
	Vector2 operator*(const Vector2& other) const {
		return { x * other.x, y * other.y };
	}
	void operator*=(const Vector2& other) {
		x *= other.x;
		y *= other.y;
	}
	// scalar
	Vector2 operator*(Type scalar) const {
		return { x * scalar, y * scalar };
	}
	void operator*=(Type scalar) {
		x *= scalar;
		y += scalar;
	}
};

using Vector2f = Vector2 <float>;
using Vector2i = Vector2 <int>;

namespace Vector {
	float CalculateLength(const Vector2f& posA, const Vector2f& posB);
}