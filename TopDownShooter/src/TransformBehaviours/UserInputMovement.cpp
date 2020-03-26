#include "UserInputMovement.h"
#include "../Components/Transform.h"
#include <SFML/Window/Keyboard.hpp>
#include "../Events/AnimationEvent.h"

UserInputMovement::UserInputMovement(float speed) 
 : m_speed(speed) {}

void UserInputMovement::setTransformComponent(std::weak_ptr<Transform> transform) {
	m_transform = transform;
}

void UserInputMovement::update(float deltaTime) {
	auto transform = m_transform.lock();

	if (transform) {
		AnimationEvent animation;
		animation.data.row = 1;
		animation.data.interval = 1000;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			transform->move(0, -m_speed * deltaTime);
			animation.data.shouldAnimate = true;
			animation.data.column = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			transform->move(-m_speed * deltaTime, 0);
			animation.data.shouldAnimate = true;
			animation.data.column = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			transform->move(0, m_speed * deltaTime);
			animation.data.shouldAnimate = true;
			animation.data.column = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			transform->move(m_speed * deltaTime, 0);
			animation.data.shouldAnimate = true;
			animation.data.column = 3;
		}

		transform->dispatchEventToParent(animation);
	}
}