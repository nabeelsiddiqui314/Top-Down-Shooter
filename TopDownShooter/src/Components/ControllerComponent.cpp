#include "ControllerComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "../Events/TransformEvent.h"
#include "../Events/AnimationEvent.h"

ControllerComponent::ControllerComponent(std::weak_ptr<Entity> parent, float speed)
 : IComponent(parent),
   m_speed(speed) {}

void ControllerComponent::update(float deltaTime) {
	TransformEvent move;
	move.transformVector = { 0, 0 };
	move.type = TransformEvent::Type::CHANGE;

	AnimationEvent animation;
	animation.data.shouldAnimate = false;
	animation.data.row = 3;
	animation.data.interval = 50;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		move.transformVector = { 0, -m_speed };
		animation.data.shouldAnimate = true;
		animation.data.column = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move.transformVector = { -m_speed, 0 };
		animation.data.shouldAnimate = true;
		animation.data.column = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move.transformVector = { 0, m_speed };
		animation.data.shouldAnimate = true;
		animation.data.column = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move.transformVector = { m_speed, 0 };
		animation.data.shouldAnimate = true;
		animation.data.column = 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		destroyParent();
	}

	dispatchEventToParent(move);
	dispatchEventToParent(animation);
}