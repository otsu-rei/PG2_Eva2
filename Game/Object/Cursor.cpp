#include "Cursor.h"

namespace {
	float Lerp(float t, float begin, float end) {
		return (1.0f - t) * begin + t * end;
	}
}

Cursor::Cursor(float bulletRadius) {
	Init(bulletRadius);
}

Cursor::~Cursor() {
}

void Cursor::Init(float bulletRadius) {
	radius_ = bulletRadius;
}

void Cursor::Update() {

}

void Cursor::Draw(const Vector3f& pos) {
	{
		Vector2f screenPos = zBuffer::ChangeScreenPos({ pos.x, pos.y, pos.z + 15.0f });
		Vector2f screenSize = zBuffer::ChangeScreenSize({ pos.x, pos.y, pos.z + 15.0f }, { radius_ * 2.0f, radius_ * 2.0f });

		DrawMethod::DrawBox(
			{ screenPos.x - screenSize.x / 2.0f, screenPos.y - screenSize.y / 2.0f },
			{ screenSize },
			0.0f,
			0x5050FA30,
			pos.z + 15.0f,
			kFillModeSolid,
			kBlendModeAdd
		);
	}
	
	{
		Vector2f screenPos = zBuffer::ChangeScreenPos({ pos.x, pos.y, pos.z + 10.0f });
		Vector2f screenSize = zBuffer::ChangeScreenSize({ pos.x, pos.y, pos.z + 10.0f }, { radius_ * 2.0f, radius_ * 2.0f });

		DrawMethod::DrawBox(
			{ screenPos.x - screenSize.x / 2.0f, screenPos.y - screenSize.y / 2.0f },
			{ screenSize },
			0.0f,
			0x5050FAFF,
			pos.z + 10.0f,
			kFillModeWireFrame
		);
	}
}
