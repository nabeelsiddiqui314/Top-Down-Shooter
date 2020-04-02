#include "ControllerComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../Components/TransformComponent.h"
#include "../Events/GunFireEvent.h"

ControllerComponent::ControllerComponent(std::weak_ptr<Entity> parent, float speed)
 : IComponent(parent),
   m_speed(speed) {}

void ControllerComponent::init() {
	if (hasComponent<TransformComponent>()) {
		m_transformComponent = getComponent<TransformComponent>();
	}
}

void ControllerComponent::update(float deltaTime) {
	m_transformComponent.lock()->setVelocity(0, 0);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		if (!m_wasPressed) {
			GunFireEvent fireEvent;
			fireEvent.pos = m_transformComponent.lock()->getPosition();
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
		m_transformComponent.lock()->setVelocity(0, -m_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_transformComponent.lock()->setVelocity(-m_speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_transformComponent.lock()->setVelocity(0, m_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_transformComponent.lock()->setVelocity(m_speed, 0 );
	}
}