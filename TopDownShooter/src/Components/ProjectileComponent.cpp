#include "ProjectileComponent.h"
#include "../Events/TransformEvent.h"

ProjectileComponent::ProjectileComponent(std::weak_ptr<Entity> parent, float velocityX, float velocityY)
 : IComponent(parent),
   m_velocity({ velocityX, velocityY }) {}

void ProjectileComponent::update(float deltaTime) {
	TransformEvent moveEvnt;
	moveEvnt.type = TransformEvent::Type::CHANGE;
	moveEvnt.transformVector = m_velocity;
	dispatchEventToParent(moveEvnt);
}