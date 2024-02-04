#include "CollisionManager.h"

void CollisionManager::CheckCollision(Entity* entity, Bullet* bullet) {
	if (entity->GetIsAlive()) {
		for (auto it = bullet->GetBullet().begin(); it != bullet->GetBullet().end();) {
			float depth = entity->GetPos().z - it->pos.z;

			if (std::abs(depth) <= bullet->GetHitDepthRange()) { // zDepthがRange範囲内の時
				if (Collider::CollisionCircleCirlce(
					{ entity->GetPos().x, entity->GetPos().y }, entity->GetRadius(),
					{ it->pos.x, it->pos.y }, bullet->GetRadius()
				)) {

					entity->SetIsAlive(false);
					it = bullet->GetBullet().erase(it);
					break;
				}
			}

			it++;
		}
	}
}
