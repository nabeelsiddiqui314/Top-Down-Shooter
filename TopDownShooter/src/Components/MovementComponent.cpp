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
	m_velocityAttribute->velocity.x = 0;
	m_velocityAttribute->velocity.y = 0;

	if (m_directionAttribute->getDirection(Direction::UP)) {
		m_velocityAttribute->velocity.y = -m_speed;
	}
	if (m_directionAttribute->getDirection(Direction::DOWN)) {
		m_velocityAttribute->velocity.y = m_speed;
	}
	if (m_directionAttribute->getDirection(Direction::LEFT)) {
		m_velocityAttribute->velocity.x = -m_speed;
	}
	if (m_directionAttribute->getDirection(Direction::RIGHT)) {
		m_velocityAttribute->velocity.x = m_speed;
	}

	m_directionAttribute->setDirection(Direction::UP, false);
	m_directionAttribute->setDirection(Direction::DOWN, false);
	m_directionAttribute->setDirection(Direction::LEFT, false);
	m_directionAttribute->setDirection(Direction::RIGHT, false);
}

void MovementComponent::setMovementDirection(const Direction& direction) {
	m_directionAttribute->setDirection(direction, true);
}