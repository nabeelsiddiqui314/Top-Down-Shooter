#pragma once
#include "IAttribute.h"
#include <bitset>

class DirectionAttribute : public IAttribute {
public:
	enum Directions {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	std::bitset<5> directions;
};