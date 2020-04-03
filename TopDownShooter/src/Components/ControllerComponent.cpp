#include "ControllerComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../Components/TransformComponent.h"
#include "../Events/GunFireEvent.h"
#include <SFML/Graphics/RenderWindow.hpp>

ControllerComponent::ControllerComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, float speed)
	: IComponent(parent),
	  m_window(window),
   m_speed(speed) {}

void ControllerComponent::init() {
	if (hasComponent<TransformComponent>()) {
		m_transformComponent = getComponent<TransformComponent>();
		m_transformComponent.lock()->setOrigin(30, 33);
	}
}

void ControllerComponent::update(float deltaTime) {
	auto transformComponent = m_transformComponent.lock();
	if (transformComponent) {
		transformComponent->setVelocity(0, 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			transformComponent->setVelocity(0, -m_speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			transformComponent->setVelocity(-m_speed, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			transformComponent->setVelocity(0, m_speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			transformComponent->setVelocity(m_speed, 0);
		}

		sf::Vector2f toMouse = { sf::Mouse::getPosition(*m_window).x - transformComponent->getPosition().x,
			sf::Mouse::getPosition(*m_window).y - transformComponent->getPosition().y };

		float rotation = atan2f(toMouse.y, toMouse.x);
		transformComponent->setRotation(rotation);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (!m_wasPressed) {
				GunFireEvent fireEvent;	
				fireEvent.pos = transformComponent->getPosition();
				fireEvent.rotation = rotation;
				fireEvent.velocity = 100.0f;
				fireEvent.bulletTexture = "bullet.png";
				dispatchEventToParent(fireEvent);
				m_wasPressed = true;
			}
		}
		else {
			m_wasPressed = false;
		}
	}
}