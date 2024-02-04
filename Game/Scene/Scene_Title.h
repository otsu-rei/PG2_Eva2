#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#include "IScene.h"
#include "GameTextureManager.h"

////////////////////////////////////////////////////////////////////////////////////////////
// Scene_Title class
////////////////////////////////////////////////////////////////////////////////////////////
class Scene_Title
	: public IScene {
public:

	Scene_Title();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:



};