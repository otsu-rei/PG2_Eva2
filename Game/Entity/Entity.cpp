#include "Entity.h"

#include "Environment.h"

void Entity::Clamp() {
	if (pos_.x - size_.x / 2.0f < 0.0f) {
		pos_.x = size_.x / 2.0f;

	} else if (pos_.x + size_.x / 2.0f > kWindowWidth) {
		pos_.x = kWindowWidth - size_.x / 2.0f;
	}

	if (pos_.y - size_.y / 2.0f < 0.0f) {
		pos_.y = size_.y / 2.0f;

	} else if (pos_.y + size_.y / 2.0f > kWindowHeight) {
		pos_.y = kWindowHeight - size_.y / 2.0f;
	}

	if (pos_.z < 0.0f) {
		pos_.z = 0.0f;
	}
}
