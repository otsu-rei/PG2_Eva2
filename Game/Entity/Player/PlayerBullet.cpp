#include "PlayerBullet.h"

//-----------------------------------------------------------------------------------------
// static init
//-----------------------------------------------------------------------------------------
const std::string PlayerBullet::path_ = "player/playerBullet.json";

PlayerBullet::PlayerBullet() {
	Init();
}

PlayerBullet::~PlayerBullet() {
	bullets_.clear();
}

void PlayerBullet::Init() {
	LoadJson();
}

void PlayerBullet::Update() {
	for (auto it = bullets_.begin(); it != bullets_.end();) {
		
		it->pos.z += speed_;

		if (it->pos.z > 30.0f) {
			it = bullets_.erase(it);
			continue;
		}

		it++;
	}
}

void PlayerBullet::Draw() {
	for (const auto& bullet : bullets_) {
		Vector2f screenPos = zBuffer::ChangeScreenPos(bullet.pos);
		Vector2f screenSize = zBuffer::ChangeScreenSize(bullet.pos, size_);

		DrawMethod::DrawEllipse(
			{ screenPos },
			{ screenSize },
			0.0f,
			0x0000FA20,
			bullet.pos.z,
			kFillModeSolid,
			kBlendModeNormal
		);

		DrawMethod::DrawEllipse(
			{ screenPos },
			{ screenSize },
			0.0f,
			0x0000FAFF,
			bullet.pos.z,
			kFillModeWireFrame
		);
	}
}

void PlayerBullet::AddBullet(const Vector3f& pos) {
	Object bullet;
	bullet.pos = pos;

	bullets_.push_back(bullet);
}

void PlayerBullet::LoadJson() {
	Json parameter = JsonAdapter::ReadJson(path_);

	size_ = {
		parameter["size"]["x"],
		parameter["size"]["y"],
	};

	speed_ = parameter["speed"];
	hitDepthRange_ = parameter["range"];

	radius_ = parameter["radius"];
}
