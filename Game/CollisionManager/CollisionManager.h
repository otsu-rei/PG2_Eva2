#pragma once

#include "Entity.h"
#include "Bullet.h"

class CollisionManager {
public:

	static void CheckCollision(Entity* entity, Bullet* bullet);

};