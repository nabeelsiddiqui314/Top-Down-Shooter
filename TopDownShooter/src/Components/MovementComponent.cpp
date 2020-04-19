#include "MovementComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/VelocityAttribute.h"
#include "../Attributes/DirectionAttribute.h"

MovementComponent::MovementComponent(float speed) 
	: m_speed(speed) {}

void MovementComponent::initAttributes(std::shared_ptr<AttributeManager> attributes) {
	m_velocityAttribute = attributes->addAttribue<VelocityAttribute>();
	m_directionAttribute = attributes->addAttribue<DirectionAttribute>();

	m_directionAttribute.lock()->directions[DirectionAttribute::RIGHT] = true;
	m_directionAttribute.lock()->directions[DirectionAttribute::DOWN] = true;
}

void MovementComponent::update(float deltaTime) {
	auto velocityAttrib = m_velocityAttribute.lock();
	auto directionAttrib = m_directionAttribute.lock();

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