#include "TransformComponent.h"
#include "../Events/TransformEvent.h"

TransformComponent::TransformComponent(std::weak_ptr<Entity> parent)
 : IComponent(parent) {}

void TransformComponent::update(float deltaTime) {
	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
}

void TransformComponent::handleEvent(const TransformEvent& event)  {
	if (event.type == TransformEvent::Type::CHANGE) {
		m_velocity = event.transformVector;
	}
}