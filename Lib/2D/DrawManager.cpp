#include "DrawManager.h"

void DrawManager::AddElement(const SortDrawElement& element) {
	elements_.push_back(element);
}

void DrawManager::Draw() {
	SortDepth();

	while (!elements_.empty()) {
		const auto& element = elements_.front();
		element.Draw();

		elements_.pop_front();
	}

	ClearStack();
}

void DrawManager::ClearStack() {
	if (elements_.empty()) {
		return;

	} else {
		assert(false);
		elements_.clear();
	}
}

DrawManager::DrawManager() {
}

DrawManager::~DrawManager() {
}

void DrawManager::SortDepth() {
	std::sort(elements_.begin(), elements_.end(), [](const auto& a, const auto& b) {
		// layerが大きいほど先に描画
		return a.depth > b.depth;
	});
}

DrawManager* DrawManager::GetInstance() {
	static DrawManager instance;
	return &instance;
}
