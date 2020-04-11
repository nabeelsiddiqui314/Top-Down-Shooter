#include "ControllerComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Events/GunFireEvent.h"
#include "../Events/MoveEvent.h"

ControllerComponent::ControllerComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window)
	: IComponent(parent),
      m_window(window) {}

void ControllerComponent::update(float deltaTime) {
	MoveEvent MoveEvent;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		MoveEvent.directions[MoveEvent::MoveDirection::UP] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		MoveEvent.directions[MoveEvent::MoveDirection::LEFT] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		MoveEvent.directions[MoveEvent::MoveDirection::DOWN] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		MoveEvent.directions[MoveEvent::MoveDirection::RIGHT] = true;
	}
	MoveEvent.lookingAt.x = sf::Mouse::getPosition(*m_window).x;
	MoveEvent.lookingAt.y = sf::Mouse::getPosition(*m_window).y;

	dispatchEventToParent(MoveEvent);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!m_wasPressed) {
			GunFireEvent fireEvent;	
			fireEvent.velocity = 100.0f;
			fireEvent.bulletName = "bullet.png";
			dispatchEventToParent(fireEvent);
			m_wasPressed = true;
		}
	}
	else {
		m_wasPressed = false;
	}
}