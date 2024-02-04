#pragma once
#include <Novice.h>
#include <cmath>
#include <assert.h>

// Library > Geometry //
#include "MyVector3.h"

enum RotateType {
	BASE_X,
	BASE_Y,
	BASE_Z
};

class Matrix4x4 {
private:

	static const int kRowHeight = 24;
	static const int kColomWidth = 70;

public:

	static const int kMaxRow = 4;
	static const int kMaxColumn = 4;

	float m[kMaxRow][kMaxColumn];

	/// operator overload ///
	/* Add */
	Matrix4x4 operator+(const Matrix4x4& other) const {
		Matrix4x4 result;

		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				result.m[row][column] = m[row][column] + other.m[row][column];
			}
		}

		return result;
	}
	void operator+=(const Matrix4x4& other) {
		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				m[row][column] += other.m[row][column];
			}
		}
	}

	/* Subtract */
	Matrix4x4 operator-(const Matrix4x4& other) const {
		Matrix4x4 result;

		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				result.m[row][column] = m[row][column] - other.m[row][column];
			}
		}

		return result;
	}
	void operator-=(const Matrix4x4& other) {

		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				m[row][column] -= other.m[row][column];
			}
		}
	}

	/* Multiply */
	Matrix4x4 operator*(const Matrix4x4& other) const {
		Matrix4x4 result = { 0.0f };

		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				for (int i = 0; i < 4; i++) {
					result.m[row][column] += m[row][i] * other.m[i][column];
				}
			}
		}

		return result;
	}
	void operator*=(const Matrix4x4& other) {
		Matrix4x4 result = { 0.0f };

		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				for (int i = 0; i < 4; i++) {
					result.m[row][column] += m[row][i] * other.m[i][column];
				}
			}
		}

		for (int row = 0; row < kMaxRow; row++) {
			for (int column = 0; column < kMaxColumn; column++) {
				m[row][column] = result.m[row][column];
			}
		}
	}


	/// user method ///

	static Matrix4x4 MakeScale(const Vector3f& scale);

	static Matrix4x4 MakeRotate(float radian, RotateType type);
	static Matrix4x4 MakeRotate(const Vector3f& radian);

	static Matrix4x4 MakeTranslate(const Vector3f& translate);

	static Matrix4x4 MakeAffin(const Vector3f& scale, const Vector3f& rotate, const Vector3f& translate);

	static Matrix4x4 Inverse(const Matrix4x4& m);
	static Matrix4x4 InverseGPT(const Matrix4x4& m);

	// graphics //
	/* 透視投影行列 */
	static Matrix4x4 MakePerspectiveFov(float fovY, float aspectRatio, float nearClip, float farClip);
	/* 正射影行列 */
	static Matrix4x4 MakeOrthographic(float left, float top, float right, float bottom, float nearZ, float farZ);
	/* ビューポート変換 */
	static Matrix4x4 MakeViewport(float left, float top, float width, float height, float minDepth, float maxDepth);


	static Vector3f Transform(const Vector3f& vector, const Matrix4x4& matrix);

	static void ScreenPrintf(int x, int y, const Matrix4x4& matrix);

};

namespace Matrix4x4Operations {
// ...
}