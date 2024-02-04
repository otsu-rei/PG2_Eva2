#pragma once

//-----------------------------------------------------------------------------------------
// Include
//-----------------------------------------------------------------------------------------
#include <deque>
#include <algorithm>
#include <cassert>

#include "DrawElement.h"

////////////////////////////////////////////////////////////////////////////////////////////
// DrawManager class
////////////////////////////////////////////////////////////////////////////////////////////
class DrawManager {
public:

	void AddElement(const SortDrawElement& element);
	void Draw();

	void ClearStack();

private:

	DrawManager();
	~DrawManager();

	std::deque<SortDrawElement> elements_;

	void SortDepth();

public:

	static DrawManager* GetInstance();
	DrawManager& operator=(const DrawManager& obj) = delete;
	DrawManager(const DrawManager& obj) = delete;
};