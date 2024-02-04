#pragma once

#include <map>
#include <string>
#include <assert.h>

enum class kAudioType {
	BGM,
	SE
};

struct AudioElement {
	float defaultVolume;
	kAudioType type;
	std::string filePath;
	int audioHandle;
};

class GameAudioManager {
public: // member method

	// Constructor & Destructor
	GameAudioManager();
	~GameAudioManager();

	// default method
	static void Load();
	static void Finalize();

private: // member object

	static std::map<std::string, AudioElement> audios_;

public: 

	static AudioElement GetElement(std::string key) { 
		assert(audios_.find(key) != audios_.end());
		// Error: "std::string key"が正しいか確認してください。

		return audios_[key];
	}

	static float masterVolume_;

};

