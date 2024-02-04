#include "EnemyBullet.h"

const std::string EnemyBullet::jsonPath_ = "enemy/enemyBullet.json";

EnemyBullet::EnemyBullet() {
	Init();
}

EnemyBullet::~EnemyBullet() {
	Finalize();
}

void EnemyBullet::Init() {
}

void EnemyBullet::Update() {
	for (auto it = bullets_.begin(); it != bullets_.end();) {
		it->pos += it->velocity;

		if (it->pos.z < 0.0f) {
			it = bullets_.erase(it);
			continue;
		}

		it++;
	}
}

void EnemyBullet::Draw() {
}

void EnemyBullet::Finalize() {
	bullets_.clear();
}

void EnemyBullet::AddBullet(const Vector3f& enemyPos, const Vector3f& playerPos) {
	Object bullet;
	bullet.pos = enemyPos;

	Vector3f direction = Vector::CalculateDirection(enemyPos, playerPos);
	Vector::Normalize(direction);

	bullet.velocity = direction;

	bullets_.push_back(bullet);
}

void EnemyBullet::LoadJson() {
	Json parameters = JsonAdapter::ReadJson(jsonPath_);

	size_ = {
		parameters["size"]["x"],
		parameters["size"]["y"],
	};


}
