#pragma once
#include "IAttribute.h"
#include <cstdint>

class AnimationAttribute : public IAttribute {
public:
	int row = 0;
	int column = 0;
	bool isAnimating = false;
	float interval = 0.1f;
};