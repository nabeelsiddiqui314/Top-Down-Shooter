#include "ProjectileComponent.h"
#include "TransformComponent.h"

ProjectileComponent::ProjectileComponent(std::weak_ptr<Entity> parent, float velocity, float rotation)
 : IComponent(parent),
   m_velocity(velocity),
   m_rotation(rotation) {}

void ProjectileComponent::init() {
	if (hasComponent<TransformComponent>()) {
		m_transformComponent = getComponent<TransformComponent>();
		m_transformComponent.lock()->setVelocity(m_velocity * cosf(m_rotation), m_velocity * sinf(m_rotation));
	}
}

void ProjectileComponent::update(float deltaTime) {}