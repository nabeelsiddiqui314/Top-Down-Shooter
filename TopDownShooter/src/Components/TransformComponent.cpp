#include "TransformComponent.h"

TransformComponent::TransformComponent(std::weak_ptr<Entity> parent)
 : IComponent(parent) {}

TransformComponent::TransformComponent(std::weak_ptr<Entity> parent, float x, float y)
 : IComponent(parent) {
	m_position = { x, y };
}

void TransformComponent::update(float deltaTime) {
	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
}

void TransformComponent::setVelocity(float x, float y) {
	m_velocity.x = x;
	m_velocity.y = y;
}

const sf::Vector2f& TransformComponent::getPosition() const {
	return m_position;
}
