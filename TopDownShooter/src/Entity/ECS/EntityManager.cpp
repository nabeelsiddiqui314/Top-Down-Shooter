#include "EntityManager.h"

Entity_ID EntityManger::createEntity() {
	if (m_unusedEntityQueue.size() == 0) {
		m_componentBitsets.emplace_back();
		return m_lastNewEntity++;
	}
	else {
		Entity_ID entity = m_unusedEntityQueue.front();
		m_unusedEntityQueue.pop();
		return entity;
	}
}

void EntityManger::setComponentFlag(Entity_ID entity, Component_ID component, bool value) {
	m_componentBitsets[entity][component] = value;
}

const ComponentBitset EntityManger::getComponentBitmask(Entity_ID entity) const {
	return m_componentBitsets[entity];
}

void EntityManger::destroyEntity(Entity_ID entity) {
	m_unusedEntityQueue.push(entity);
	m_componentBitsets[entity].reset();
}