#include "DrawElement.h"

void DrawElement::Draw() const {
	Novice::SetBlendMode(blendMode);

	switch (type) {
		case kLine:
			Novice::DrawLine(
				static_cast<int>(pos[0].x),
				static_cast<int>(pos[0].y),
				static_cast<int>(pos[1].x),
				static_cast<int>(pos[1].y),
				color
			);
			break;

		case kTriangle:
			Novice::DrawTriangle(
				static_cast<int>(pos[0].x),
				static_cast<int>(pos[0].y),
				static_cast<int>(pos[1].x),
				static_cast<int>(pos[1].y),
				static_cast<int>(pos[2].x),
				static_cast<int>(pos[2].y),
				color,
				fillMode
			);
			break;

		case kEllipse:
			Novice::DrawEllipse(
				static_cast<int>(pos[0].x),
				static_cast<int>(pos[0].y),
				static_cast<int>(size.x),
				static_cast<int>(size.y),
				angle,
				color,
				fillMode
			);
			break;

		case kBox:
			Novice::DrawBox(
				static_cast<int>(pos[0].x),
				static_cast<int>(pos[0].y),
				static_cast<int>(size.x),
				static_cast<int>(size.y),
				angle,
				color,
				fillMode
			);
			break;

		case kQuad:
			Novice::DrawQuad(
				static_cast<int>(pos[0].x),
				static_cast<int>(pos[0].y),
				static_cast<int>(pos[1].x),
				static_cast<int>(pos[1].y),
				static_cast<int>(pos[2].x),
				static_cast<int>(pos[2].y),
				static_cast<int>(pos[3].x),
				static_cast<int>(pos[3].y),
				textureRectPos.x,
				textureRectPos.y,
				textureRectSize.x,
				textureRectSize.y,
				textureHandle,
				color
			);
			break;

		case kSprite:
			break;
		case kSpriteRect:
			break;
	}
}
