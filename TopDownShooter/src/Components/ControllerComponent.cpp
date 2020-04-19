#include "ControllerComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/DirectionAttribute.h"
#include <SFML/Window/Keyboard.hpp>

void ControllerComponent::fetchAttributes(std::shared_ptr<AttributeManager> attributes) {
	if (attributes->hasAttribute<DirectionAttribute>()) {
		m_directionAttribute = attributes->getAttribute<DirectionAttribute>();
	}
}

void ControllerComponent::update(float) {
	auto directionAttrib = m_directionAttribute.lock();

	if (directionAttrib) {
		directionAttrib->directions[DirectionAttribute::Directions::UP] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		directionAttrib->directions[DirectionAttribute::Directions::LEFT] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		directionAttrib->directions[DirectionAttribute::Directions::DOWN] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		directionAttrib->directions[DirectionAttribute::Directions::RIGHT] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	}
}
