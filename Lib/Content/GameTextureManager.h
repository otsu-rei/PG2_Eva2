#pragma once
// Novice ---
#include <Novice.h>

// ImGui ---
#include <ImGui.h>

// std:: ---
#include <map>
#include <string>

// assert ---
#include <assert.h>

struct TextureElement {
	std::string filePath;
	int handle;
};

class GameTextureManager final {
public: // default method //

	GameTextureManager();
	~GameTextureManager();

	static void Load();

private: // menber object //

	static std::map<std::string, TextureElement> texture_;

public: // user method //

	static void HotReload();

	static void TextureManagerImGui(); // TODO: 

public: // accessor //

	static int GetHandle(std::string textureName) {
		assert(texture_.find(textureName) != texture_.end());
		// 引数 textureName が正しいかどうか確認してね ;)

		return texture_[textureName].handle;
	}

};

