#include "GameTextureManager.h"

std::map<std::string, TextureElement> GameTextureManager::texture_;

/* -----------------------------------------------------------------------------------------
 default method
----------------------------------------------------------------------------------------- */
GameTextureManager::GameTextureManager() {
	Load();
}

GameTextureManager::~GameTextureManager() {
}

void GameTextureManager::Load() {
	// texture_[textureName] = { handle , filePath };
	texture_["white1x1"] = { "./NoviceResources/white1x1.png" };
	texture_["title"] = { "./Resources/images/title.png" };

	for (auto it = texture_.begin(); it != texture_.end(); it++) {
		it->second.handle = Novice::LoadTexture(it->second.filePath.c_str());
	}
}

/* -----------------------------------------------------------------------------------------
 user method
----------------------------------------------------------------------------------------- */
void GameTextureManager::HotReload() {
	for (auto it = texture_.begin(); it != texture_.end(); it++) {
		Novice::UnloadTexture(it->second.handle);
		it->second.handle = Novice::LoadTexture(it->second.filePath.c_str());
	}
}

void GameTextureManager::TextureManagerImGui() {
	static std::string result = "";
	static std::string output = "";

	ImGui::Begin("TextureManager Window");

	if (ImGui::Button("HotReload")) {
		HotReload();
		result = "HotReload() was executed";
	}

	output = "Resurt: " + result;
	ImGui::Text(output.c_str());

	ImGui::End();
}
