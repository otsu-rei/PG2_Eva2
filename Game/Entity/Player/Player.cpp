#include "Player.h"

#include "InputManager.h"
#include "Json.h"

Player::Player() {
	Init();
}

Player::~Player() {
	SafeDelete(bullet_);
}

void Player::Init() {
	LoadJson();

	bullet_ = new PlayerBullet();
	cursor_ = new Cursor(bullet_->GetRadius());
}

void Player::Update() {
	velocity_ = { 0.0f };

	if (InputManager::IsPressKeys(DIK_W)) {
		velocity_.y -= speed_;
	}

	if (InputManager::IsPressKeys(DIK_S)) {
		velocity_.y += speed_;
	}

	if (InputManager::IsPressKeys(DIK_A)) {
		velocity_.x -= speed_;
	}

	if (InputManager::IsPressKeys(DIK_D)) {
		velocity_.x += speed_;
	}

	if (InputManager::IsTriggerKeys(DIK_SPACE)) {
		bullet_->AddBullet(pos_);
	}

	pos_ += velocity_;

	Clamp();

	UpdateBullet();
}

void Player::Draw() {
	Vector2f screenPos = zBuffer::ChangeScreenPos(pos_);
	Vector2f screenSize = zBuffer::ChangeScreenSize(pos_, size_);

	cursor_->Draw(pos_);
	bullet_->Draw();

	DrawMethod::DrawBox(
		{ screenPos.x - screenSize.x / 2.0f, screenPos.y - screenSize.y / 2.0f },
		{ screenSize },
		0.0f,
		0xFAFAFA30,
		pos_.z,
		kFillModeSolid,
		kBlendModeAdd
	);

	DrawMethod::DrawBox(
		{ screenPos.x - screenSize.x / 2.0f, screenPos.y - screenSize.y / 2.0f },
		{ screenSize },
		0.0f,
		0xFAFAFAFF,
		pos_.z,
		kFillModeWireFrame
	);
}

void Player::Finalize() {
	SafeDelete(bullet_);
	SafeDelete(cursor_);
}

void Player::ImGui() {
#ifdef _DEBUG

	ImGui::Begin("Game");

	if (ImGui::TreeNode("player")) {
		ImGui::DragFloat3("pos", &pos_.x, 1.0f);

		ImGui::TreePop();
	}

	ImGui::End();

#endif // _DEBUG
}

void Player::LoadJson() {
	Json parameters = JsonAdapter::ReadJson(jsonPath_);

	pos_ = {
		parameters["pos"]["x"],
		parameters["pos"]["y"],
		parameters["pos"]["z"],
	};

	size_ = {
		parameters["size"]["x"],
		parameters["size"]["y"],
	};

	speed_ = parameters["speed"];
}

void Player::UpdateBullet() {
	bullet_->Update();
}
