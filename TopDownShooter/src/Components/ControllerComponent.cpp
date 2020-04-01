#include "ControllerComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../Components/TransformComponent.h"
#include "../Events/AnimationEvent.h"
#include "../Events/GunFireEvent.h"

ControllerComponent::ControllerComponent(std::weak_ptr<Entity> parent, float speed)
 : IComponent(parent),
   m_speed(speed) {}

void ControllerComponent::update(float deltaTime) {
	AnimationEvent animation;
	animation.data.shouldAnimate = false;
	animation.data.row = 3;
	animation.data.interval = 50;

	getTransformComponent()->setVelocity(0, 0);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		if (!m_wasPressed) {
			GunFireEvent fireEvent;
			fireEvent.pos = getTransformComponent()->getPosition();
			fireEvent.velocity = { 100.0f, 0.0f };
			fireEvent.bulletTexture = "bullet.png";
			dispatchEventToParent(fireEvent);
			m_wasPressed = true;
		}
	}
	else {
		m_wasPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		getTransformComponent()->setVelocity(0, -m_speed);
		animation.data.shouldAnimate = true;
		animation.data.column = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		getTransformComponent()->setVelocity(-m_speed, 0);
		animation.data.shouldAnimate = true;
		animation.data.column = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		getTransformComponent()->setVelocity(0, m_speed);
		animation.data.shouldAnimate = true;
		animation.data.column = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		getTransformComponent()->setVelocity(m_speed, 0 );
		animation.data.shouldAnimate = true;
		animation.data.column = 3;
	}
	dispatchEventToParent(animation);
}