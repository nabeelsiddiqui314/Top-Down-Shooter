#include "Transform.h"
#include "../Events/TransformEvent.h"

Transform::Transform(std::weak_ptr<Entity> parent)
 : IComponent(parent) {}

void Transform::update(float deltaTime) {
	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
}

void Transform::handleEvent(const TransformEvent& event)  {
	if (event.type == TransformEvent::Type::CHANGE) {
		m_velocity = event.transformVector;
	}
}