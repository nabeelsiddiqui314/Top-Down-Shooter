#include "ProjectileComponent.h"
#include "TransformComponent.h"

ProjectileComponent::ProjectileComponent(std::weak_ptr<Entity> parent, float velocityX, float velocityY)
 : IComponent(parent),
   m_velocity({ velocityX, velocityY }) {}

void ProjectileComponent::update(float deltaTime) {
	getTransformComponent()->setVelocity(m_velocity.x, m_velocity.y);
}