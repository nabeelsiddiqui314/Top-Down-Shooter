#include "Entity.h"

Entity::Entity(Entity_ID entity, std::weak_ptr<EntityManager> entityManager,
	std::weak_ptr<ComponentRegistry> componentRegistry, std::weak_ptr<SystemManager> systemManager)
	: m_entityID(entity),
	  m_entityManager(entityManager),
	  m_componentRegistry(componentRegistry),
      m_systemManager(systemManager) {}

Entity_ID Entity::getID() const {
	return m_entityID;
}

bool Entity::operator<(const Entity& entity) const {
	return m_entityID < entity.m_entityID;
}

void Entity::remove() {
	m_componentRegistry.lock()->removeEntity(m_entityID);
	m_systemManager.lock()->notifyEntityRemoval(*this);
}