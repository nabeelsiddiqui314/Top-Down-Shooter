#pragma once
#include "IAttribute.h"
#include <SFML/System/Vector2.hpp>

class TransformAttribute : public IAttribute {
public:
	sf::Vector2f position;
	float rotation;
};