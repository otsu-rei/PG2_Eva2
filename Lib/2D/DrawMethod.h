#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#include "DrawManager.h"
#include "MyMath.h"

////////////////////////////////////////////////////////////////////////////////////////////
// DrawMethod class
////////////////////////////////////////////////////////////////////////////////////////////
class DrawMethod {
public:

	static void DrawLine(
		const Vector2f& posA, const Vector2f& posB, uint32_t color, float depth,
		FillMode fillMode = kFillModeSolid, BlendMode blendMode = kBlendModeNormal
	);

	static void DrawTriangle(
		const Vector2f& posA, const Vector2f& posB, const Vector2f& posC, uint32_t color, float depth,
		FillMode fillMode = kFillModeSolid, BlendMode blendMode = kBlendModeNormal
	);

	static void DrawEllipse(
		const Vector2f& pos, const Vector2f& size, float angle, uint32_t color, float depth,
		FillMode fillMode = kFillModeSolid, BlendMode blendMode = kBlendModeNormal
	);

	static void DrawBox(
		const Vector2f& pos, const Vector2f& size, float angle, uint32_t color, float depth,
		FillMode fillMode = kFillModeSolid, BlendMode blendMode = kBlendModeNormal
	);

	static void Draw();

	static void ClearStack();

private:

	static DrawManager* manager_;
};