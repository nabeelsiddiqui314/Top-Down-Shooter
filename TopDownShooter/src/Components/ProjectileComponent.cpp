#include "ProjectileComponent.h"
#include "TransformComponent.h"

ProjectileComponent::ProjectileComponent(std::weak_ptr<Entity> parent, float velocity, float rotation)
 : IComponent(parent),
   m_velocity(velocity),
   m_rotation(rotation) {}

void ProjectileComponent::init() {

}

void ProjectileComponent::update(float deltaTime) {}