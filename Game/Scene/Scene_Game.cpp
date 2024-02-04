#include "Scene_Game.h"

Scene_Game::Scene_Game() {
}

void Scene_Game::Init() {
	player_ = new Player();
	
	for (int ei = 0; ei < kMaxEnemyNum_; ++ei) {
		enemy_[ei] = new Enemy();
	}
}

void Scene_Game::Update() {
	player_->Update();
	player_->ImGui();

	for (int ei = 0; ei < kMaxEnemyNum_; ++ei) {
		enemy_[ei]->Update();
	}

	for (int ei = 0; ei < kMaxEnemyNum_; ++ei) {
		CollisionManager::CheckCollision(enemy_[ei], player_->GetBullet());
	}

	if (Enemy::GetDestroyNum() >= 10) {
		IScene::sceneNum_ = SCENE_CLEAR;
	}
}

void Scene_Game::Draw() {
	Novice::DrawBox(
		0, 0,
		kWindowWidth, kWindowHeight,
		0.0f,
		0x0A0A0AFF,
		kFillModeSolid
	);

	for (int i = 0; i < 20; ++i) {
		Vector2f screenPos = zBuffer::ChangeScreenPos({ 0.0f, 0.0f, static_cast<float>(i) });
		Vector2f screenSize = zBuffer::ChangeScreenSize({ 0.0f, 0.0f, static_cast<float>(i) }, { kWindowWidth, kWindowHeight });

		uint32_t color = 0x21212100;

		for (const auto& bullet : player_->GetBullet()->GetBullet()) {
			if (bullet.pos.z == i) {
				color = 0x1010FAFF;
				break;
			}
		}

		if (i <= 15) {
			color += 0xFF;

		} else {
			color += 0x30;
		}


		Novice::DrawBox(
			static_cast<int>(screenPos.x),
			static_cast<int>(screenPos.y),
			static_cast<int>(screenSize.x),
			static_cast<int>(screenSize.y),
			0.0f,
			color,
			kFillModeWireFrame
		);
	}

	for (int ei = 0; ei < kMaxEnemyNum_; ++ei) {
		enemy_[ei]->Draw();
	}

	player_->Draw();

	DrawMethod::Draw();
}

void Scene_Game::Finalize() {
	SafeDelete(player_);

	for (int ei = 0; ei < kMaxEnemyNum_; ++ei) {
		SafeDelete(enemy_[ei]);
	}
}
