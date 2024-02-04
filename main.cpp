#include <Novice.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ImGui.h>

#include <time.h>

// Lib ---
#include "Environment.h"
#include "InputManager.h"
#include "GameTextureManager.h"
#include "GameAudioManager.h"

// 2D ---
#include "DrawMethod.h"

// Scene ---
#include "IScene.h"
#include "SceneManager.h"

/***********************************
 * メイン関数 *
 ***********************************/
 // Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	GameAudioManager::Load();
	GameTextureManager::Load();

	SceneManager* sceneManager = new SceneManager();

	/***********************************
	 * ゲームループ *
	 ***********************************/
	 // ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		InputManager::Update();

		sceneManager->Run();

		// フレームの終了
		Novice::EndFrame();
		DrawMethod::ClearStack();

		// ESCキーが押されたらループを抜ける
		if (IScene::GetIsExitGame()) {
			break;
		}
	}

	SafeDelete(sceneManager);

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}