#include "CameraComponent.h"
#include "../Utilities/Camera.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/TransformAttribute.h"

CameraComponent::CameraComponent(std::shared_ptr<Camera> camera) 
	: m_camera(camera) {}

void CameraComponent::fetchAttributes(std::shared_ptr<AttributeManager> attributes) {
	if (attributes->hasAttribute<TransformAttribute>()) {
		m_transformAttribute = attributes->getAttribute<TransformAttribute>();
	}
}

void CameraComponent::update(float) {
	if (m_transformAttribute) {
		m_camera->setCentre(m_transformAttribute->position);
	}
}