#include "TransformComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/TransformAttribute.h"
#include "../Attributes/VelocityAttribute.h"

TransformComponent::TransformComponent(float x, float y) 
	: m_originalPosition(x, y),
      m_scale(1.0f, 1.0f) {}

TransformComponent::TransformComponent(float x, float y, float scaleX, float scaleY)
	: m_originalPosition(x, y), 
	m_scale(scaleX, scaleY) {}

void TransformComponent::initAttributes(std::shared_ptr<AttributeManager> attributes) {
	TransformAttribute transform;
	transform.position = m_originalPosition;
	transform.scale = m_scale;

	m_transformAttribute = attributes->addAttribue<TransformAttribute>(transform);
}

void TransformComponent::fetchAttributes(std::shared_ptr<AttributeManager> attributes) {
	if (attributes->hasAttribute<VelocityAttribute>()) {
		m_velocityAttribute = attributes->getAttribute<VelocityAttribute>();
	}
}

void TransformComponent::update(float deltaTime) {
	auto transformAttrib = m_transformAttribute.lock();
	auto velocityAttrib = m_velocityAttribute.lock();

	if (velocityAttrib) {
		transformAttrib->position.x += velocityAttrib->velocity.x * deltaTime;
		transformAttrib->position.y += velocityAttrib->velocity.y * deltaTime;
	}
}