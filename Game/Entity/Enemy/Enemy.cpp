#include "Enemy.h"

#include "Environment.h"

namespace {
	void DrawEquilateralTriangle(const Vector2f& pos, float radius, float angle, uint32_t color, float depth,
		FillMode fillMode, BlendMode blendMode = kBlendModeNormal) {
		Vector2f vertices[3];
		const float kThetaEvery = (static_cast<float>(M_PI) * 2.0f) / 3.0f;

		// 正三角形の頂点の決定
		for (int vi = 0; vi < 3; ++vi) {
			float theta = kThetaEvery * vi - static_cast<float>(M_PI) / 2.0f;

			vertices[vi] = {
				std::cos(angle + (theta)) * radius,
				std::sin(angle + (theta)) * radius,
			};
		}

		DrawMethod::DrawTriangle(
			{ pos.x + vertices[0].x, pos.y + vertices[0].y, },
			{ pos.x + vertices[1].x, pos.y + vertices[1].y, },
			{ pos.x + vertices[2].x, pos.y + vertices[2].y, },
			color,
			depth,
			fillMode,
			blendMode
		);
	}
}

const std::string Enemy::jsonPath_ = "enemy/enemy.json";
int Enemy::destroyNum_ = 0;

Enemy::Enemy() {
	Init();
}

Enemy::~Enemy() {
	Finalize();
}

void Enemy::Init() {
	LoadJson();

	pos_ = {
		Random::Generate(randomPos_.min.x, randomPos_.max.x) + size_.x / 2.0f,
		Random::Generate(randomPos_.min.y, randomPos_.max.y) + size_.y / 2.0f,
		Random::Generate(randomPos_.min.z, randomPos_.max.z)
	};

	velocity_ = {
		Random::Generate(randomVelocity_.min.x, randomVelocity_.max.x),
		Random::Generate(randomVelocity_.min.y, randomVelocity_.max.y),
		Random::Generate(randomVelocity_.min.z, randomVelocity_.max.z),
	};

	theta_ = 0.0f;
	radian_ = 0;

	respownCount_ = 0.0f;

	isAlive_ = true;

	destroyNum_ = 0;
}

void Enemy::Update() {
	if (isAlive_) {
		Move();
		Rotate();

	} else {
		if (respownCount_ == 0.0f) { destroyNum_++; }

		Respown();
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Vector2f screenPos = zBuffer::ChangeScreenPos(pos_);
		Vector2f screenSize = zBuffer::ChangeScreenSize(pos_, size_);

		DrawEquilateralTriangle(
			{ screenPos },
			size_.x,
			theta_,
			0xFA202020,
			pos_.z,
			kFillModeSolid,
			kBlendModeAdd
		);

		DrawEquilateralTriangle(
			{ screenPos },
			size_.y,
			-theta_ + static_cast<float>(M_PI),
			0xFA202030,
			pos_.z,
			kFillModeSolid,
			kBlendModeAdd
		);


		DrawEquilateralTriangle(
			{ screenPos },
			size_.x,
			theta_,
			0xFA2020FF,
			pos_.z,
			kFillModeWireFrame
		);

		DrawEquilateralTriangle(
			{ screenPos },
			size_.y,
			-theta_ + static_cast<float>(M_PI),
			0xFA2020FF,
			pos_.z,
			kFillModeWireFrame
		);
	}
}

void Enemy::Finalize() {
}

void Enemy::LoadJson() {
	Json parameters = JsonAdapter::ReadJson(jsonPath_);

	size_ = {
		parameters["size"]["x"],
		parameters["size"]["y"],
	};

	radius_ = {
		parameters["radius"]
	};

	randomPos_.min = {
		parameters["random"]["pos"]["min"]["x"],
		parameters["random"]["pos"]["min"]["y"],
		parameters["random"]["pos"]["min"]["z"],
	};

	randomPos_.max = {
		parameters["random"]["pos"]["max"]["x"],
		parameters["random"]["pos"]["max"]["y"],
		parameters["random"]["pos"]["max"]["z"],
	};

	randomVelocity_.min = {
		parameters["random"]["velocity"]["min"]["x"],
		parameters["random"]["velocity"]["min"]["y"],
		parameters["random"]["velocity"]["min"]["z"],
	};

	randomVelocity_.max = {
		parameters["random"]["velocity"]["max"]["x"],
		parameters["random"]["velocity"]["max"]["y"],
		parameters["random"]["velocity"]["max"]["z"],
	};

	respownTime_ = parameters["respownTime"];
}

void Enemy::Move() {
	pos_ += velocity_;

	if (pos_.x < 0.0f) {
		pos_.x = 0.0f;
		velocity_.x *= -1;

	} else if (pos_.x > kWindowWidth) {
		pos_.x = kWindowWidth;
		velocity_.x *= -1;
	}

	if (pos_.y < 0.0f) {
		pos_.y = 0.0f;
		velocity_.y *= -1;

	} else if (pos_.y > kWindowHeight) {
		pos_.y = kWindowHeight;
		velocity_.y *= -1;
	}

	if (pos_.z < 10.0f) {
		pos_.z = 10.0f;
		velocity_.z *= -1;

	} else if (pos_.z > 15.0f) {
		pos_.z = 15.0f;
		velocity_.z *= -1;
	}
}

void Enemy::Rotate() {
	theta_ = ++radian_ / 200.0f * (static_cast<float>(M_PI) * 2.0f);
	radian_ %= 200;
}

void Enemy::Respown() {
	respownCount_++;

	if (respownCount_ >= respownTime_) {
		respownCount_ = 0.0f;

		pos_ = {
			Random::Generate(randomPos_.min.x, randomPos_.max.x) + size_.x / 2.0f,
			Random::Generate(randomPos_.min.y, randomPos_.max.y) + size_.y / 2.0f,
			Random::Generate(randomPos_.min.z, randomPos_.max.z)
		};

		velocity_ = {
			Random::Generate(randomVelocity_.min.x, randomVelocity_.max.x),
			Random::Generate(randomVelocity_.min.y, randomVelocity_.max.y),
			Random::Generate(randomVelocity_.min.z, randomVelocity_.max.z),
		};

		isAlive_ = true;
	}
}
