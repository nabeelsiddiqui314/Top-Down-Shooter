#pragma once
#include "IAttribute.h"
#include <cstdint>

class AnimationAttribute : public IAttribute {
public:
	int row = 5;
	int column = 2;
	bool isAnimating = true;
	float interval = 0.8f;
};