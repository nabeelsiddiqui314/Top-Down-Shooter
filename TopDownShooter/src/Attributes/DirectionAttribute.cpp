#include "DirectionAttribute.h"

void DirectionAttribute::setDirection(const Direction& direction, bool value) {
	m_directions[static_cast<std::size_t>(direction)] = value;
}

bool DirectionAttribute::getDirection(const Direction& direction) const {
	return m_directions[static_cast<std::size_t>(direction)];
}