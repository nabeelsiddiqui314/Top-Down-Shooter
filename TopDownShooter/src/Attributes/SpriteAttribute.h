#pragma once
#include "IAttribute.h"
#include <SFML/Graphics/Sprite.hpp>

class SpriteAttribute : public IAttribute {
public:
	sf::Sprite sprite;
};