#include "MovementComponent.h"
#include "TransformComponent.h"
#include "../Events/MoveEvent.h"
#include <SFML/Graphics/RenderWindow.hpp>

MovementComponent::MovementComponent(std::weak_ptr<Entity> parent, const sf::Vector2f& origin, float speed)
 : IComponent(parent),
   m_speed(speed),
   m_origin(origin) {}

void MovementComponent::init() {
	if (hasComponent<TransformComponent>()) {
		m_transformComponent = getComponent<TransformComponent>();
		m_transformComponent.lock()->setOrigin(m_origin.x, m_origin.y);
	}
}

void MovementComponent::update(float deltaTime) {}

void MovementComponent::handleEvent(const MoveEvent& moveEvent) {
	m_velocity = { 0.0f, 0.0f };

	if (moveEvent.directions[MoveEvent::MoveDirection::UP]) {
		m_velocity.y -= m_speed;
	}
	if (moveEvent.directions[MoveEvent::MoveDirection::DOWN]) {
		m_velocity.y += m_speed;
	}
	if (moveEvent.directions[MoveEvent::MoveDirection::LEFT]) {
		m_velocity.x -= m_speed;
	}
	if (moveEvent.directions[MoveEvent::MoveDirection::RIGHT]) {
		m_velocity.x += m_speed;
	}

	auto transformComponent = m_transformComponent.lock();
	if (transformComponent) {
		sf::Vector2f toMouse = { moveEvent.lookingAt.x - transformComponent->getPosition().x,
			moveEvent.lookingAt.y - transformComponent->getPosition().y };

		float rotation = atan2f(toMouse.y, toMouse.x);
		transformComponent->setRotation(rotation);

		transformComponent->setVelocity(m_velocity.x, m_velocity.y);
	}
}