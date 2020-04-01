#include "ProjectileComponent.h"
#include "TransformComponent.h"

ProjectileComponent::ProjectileComponent(std::weak_ptr<Entity> parent, float velocityX, float velocityY)
 : IComponent(parent),
   m_velocity({ velocityX, velocityY }) {}

void ProjectileComponent::init() {
	if (hasComponent<TransformComponent>()) {
		m_transformComponent = getComponent<TransformComponent>();
	}
}

void ProjectileComponent::update(float deltaTime) {
	m_transformComponent.lock()->setVelocity(m_velocity.x, m_velocity.y);
}