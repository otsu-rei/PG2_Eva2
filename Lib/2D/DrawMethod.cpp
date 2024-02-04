#include "DrawMethod.h"

//-----------------------------------------------------------------------------------------
// static Init
//-----------------------------------------------------------------------------------------
DrawManager* DrawMethod::manager_ = DrawManager::GetInstance();

//-----------------------------------------------------------------------------------------
// methods
//-----------------------------------------------------------------------------------------
void DrawMethod::DrawLine(
	const Vector2f& posA, const Vector2f& posB, uint32_t color, float depth,
	FillMode fillMode, BlendMode blendMode) {

	SortDrawElement element;
	element.type = kLine;
	element.pos[0] = posA;
	element.pos[1] = posB;
	element.color = color;
	element.depth = depth;
	element.fillMode = fillMode;
	element.blendMode = blendMode;

	manager_->AddElement(element);
}

void DrawMethod::DrawTriangle(
	const Vector2f& posA, const Vector2f& posB, const Vector2f& posC, uint32_t color, float depth,
	FillMode fillMode, BlendMode blendMode) {

	SortDrawElement element;
	element.type      = kTriangle;
	element.pos[0]    = posA;
	element.pos[1]    = posB;
	element.pos[2]    = posC;
	element.color     = color;
	element.depth     = depth;
	element.fillMode  = fillMode;
	element.blendMode = blendMode;

	manager_->AddElement(element);
}

void DrawMethod::DrawEllipse(
	const Vector2f& pos, const Vector2f& size, float angle, uint32_t color, float depth,
	FillMode fillMode, BlendMode blendMode) {

	SortDrawElement element;
	element.type = kEllipse;
	element.pos[0] = pos;
	element.size = size;
	element.angle = angle;
	element.color = color;
	element.depth = depth;
	element.fillMode = fillMode;
	element.blendMode = blendMode;

	manager_->AddElement(element);
}

void DrawMethod::DrawBox(
	const Vector2f& pos, const Vector2f& size, float angle, uint32_t color, float depth,
	FillMode fillMode, BlendMode blendMode) {

	SortDrawElement element;
	element.type      = kBox;
	element.pos[0]    = pos;
	element.size      = size;
	element.angle     = angle;
	element.color     = color;
	element.depth     = depth;
	element.fillMode  = fillMode;
	element.blendMode = blendMode;

	manager_->AddElement(element);
}

void DrawMethod::Draw() {
	manager_->Draw();
}

void DrawMethod::ClearStack() {

}
