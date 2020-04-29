#pragma once
#include "IAttribute.h"
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

class SpriteAttribute : public IAttribute {
public:
	std::shared_ptr<sf::Sprite> sprite;
};