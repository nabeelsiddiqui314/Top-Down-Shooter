#include "MovementComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/VelocityAttribute.h"
#include "../Attributes/DirectionAttribute.h"

MovementComponent::MovementComponent(float speed) 
	: m_speed(speed) {}

void MovementComponent::initAttributes(std::shared_ptr<AttributeManager> attributes) {
	m_velocityAttribute = attributes->addAttribue<VelocityAttribute>();
	m_directionAttribute = attributes->addAttribue<DirectionAttribute>();
}

void MovementComponent::update(float) {
	auto velocityAttrib = m_velocityAttribute.lock();
	auto directionAttrib = m_directionAttribute.lock();

	velocityAttrib->velocity.x = 0;
	velocityAttrib->velocity.y = 0;

	if (directionAttrib->directions[DirectionAttribute::Directions::UP]) {
		velocityAttrib->velocity.y = -m_speed;
	}
	if (directionAttrib->directions[DirectionAttribute::Directions::DOWN]) {
		velocityAttrib->velocity.y = m_speed;
	}
	if (directionAttrib->directions[DirectionAttribute::Directions::LEFT]) {
		velocityAttrib->velocity.x = -m_speed;
	}
	if (directionAttrib->directions[DirectionAttribute::Directions::RIGHT]) {
		velocityAttrib->velocity.x = m_speed;
	}
}