#pragma once
#include "IAttribute.h"
#include <SFML/System/Vector2.hpp>

class VelocityAttribute : public IAttribute {
public:
	sf::Vector2f velocity;
};