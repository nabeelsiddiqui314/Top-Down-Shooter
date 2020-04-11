#include "EntityManager.h"

Entity_ID EntityManager::createEntity() {
	if (m_unusedEntityQueue.size() == 0) {
		m_componentLists.emplace_back();
		return m_lastNewEntity++;
	}
	else {
		Entity_ID entity = m_unusedEntityQueue.front();
		m_unusedEntityQueue.pop();
		return entity;
	}
}

void EntityManager::setComponentFlag(Entity_ID entity, Component_ID component, bool value) {
	m_componentLists[entity][component] = value;
}

const ComponentList EntityManager::getComponentList(Entity_ID entity) const {
	return m_componentLists[entity];
}

void EntityManager::destroyEntity(Entity_ID entity) {
	m_unusedEntityQueue.push(entity);
	m_componentLists[entity].reset();
}