#pragma once
#include "IAttribute.h"
#include <bitset>

enum class Direction : std::uint8_t {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class DirectionAttribute : public IAttribute {
public:
	void setDirection(const Direction& direction, bool value);
	bool getDirection(const Direction& direction) const;
private:
	std::bitset<5> m_directions;
};