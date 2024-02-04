#include "GameAudio.h"
#include "GameAudioManager.h"

GameAudio::GameAudio(std::string key) { Init(key); }
GameAudio::~GameAudio() { Finalize(); }


void GameAudio::Init(std::string key) {
	key_ = key;
	playHandle_ = 0;

	switch (GameAudioManager::GetElement(key_).type) {
		case kAudioType::SE:
			isPlayAudio_ = false;
			break;
		case kAudioType::BGM:
			isPlayAudio_ = true;
			break;
	}

}

void GameAudio::Finalize() {
	// 音の再生を止める -----
	StopAudio();
}

void GameAudio::PlayAudio() {

	// typeごとに再生する
	switch (GameAudioManager::GetElement(key_).type) {
		case kAudioType::BGM:
			// BGMの再生関数

			if (!Novice::IsPlayingAudio(playHandle_)) {
				playHandle_ = Novice::PlayAudio(
					GameAudioManager::GetElement(key_).audioHandle,     // handle
					true,                                               // loop
					GameAudioManager::GetElement(key_).defaultVolume
					* volume_
					* GameAudioManager::masterVolume_                   // volume
				);
			}

			break;

		case kAudioType::SE:
			// SEの再生関数
			if (isPlayAudio_) {
				playHandle_ = Novice::PlayAudio(
					GameAudioManager::GetElement(key_).audioHandle, // handle
					false,                                          // loop
					GameAudioManager::GetElement(key_).defaultVolume
					* volume_
					* GameAudioManager::masterVolume_               // volume
				);

				isPlayAudio_ = false;
			}

			break;
	}
}

void GameAudio::StopAudio() {

	// 音の再生を止める
	Novice::StopAudio(playHandle_);

}


