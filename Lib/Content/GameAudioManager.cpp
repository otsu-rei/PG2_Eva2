#include "GameAudioManager.h"

// Include -----
// Math
#include <Novice.h>

std::map<std::string, AudioElement> GameAudioManager::audios_;
float GameAudioManager::masterVolume_ = 1.0f;

GameAudioManager::GameAudioManager() { Load(); }
GameAudioManager::~GameAudioManager() { Finalize(); }

/*===================================================
	初期化関数
===================================================*/
void GameAudioManager::Load() {

	/// audioHandleにロード
	for (auto it = audios_.begin(); it != audios_.end(); it++) {
		it->second.audioHandle = Novice::LoadAudio(it->second.filePath.c_str());
	}

}


/*===================================================
	終了処理関数
===================================================*/
void GameAudioManager::Finalize() {
	audios_.clear();
}
