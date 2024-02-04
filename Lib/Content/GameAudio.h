#pragma once
#include <Novice.h>

// std:: ---
#include <string>

class GameAudio {
public: // member method

	// Constructor & Destructor
	GameAudio(std::string key);
	~GameAudio();

	// default method
	void Init(std::string key);
	void Finalize();

private: // member object

	std::string key_;
	int playHandle_;

	bool isPlayAudio_;
	float volume_;

public: // user method

	void PlayAudio();
	void StopAudio();

public: // accessor

	/*void SetIsPlayAudio(bool isPlayAudio) { isPlayAudio_ = isPlayAudio; }*/

	void SetAudio(bool isPlayAudio, float volume = 1.0f) {
		isPlayAudio_ = isPlayAudio;
		volume_ = volume;
	};
};

