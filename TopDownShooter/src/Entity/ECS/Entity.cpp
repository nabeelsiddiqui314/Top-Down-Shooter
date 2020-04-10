#include "Entity.h"

Entity::Entity(Entity_ID entity, std::weak_ptr<ComponentRegistry> componentRegistry)
	: m_componentRegistry(componentRegistry),
      m_entityID(entity) {}

bool Entity::operator<(const Entity& entity) const {
	return m_entityID < entity.m_entityID;
}

void Entity::remove() {
	m_componentRegistry.lock()->removeEntity(m_entityID);
}