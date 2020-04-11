#pragma once
#include <vector>
#include <queue>
#include "EcsTypes.h"

class EntityManager {
public:
	EntityManager() = default;
	~EntityManager() = default;
public:
	Entity_ID createEntity();
	void destroyEntity(Entity_ID entity);
	
	void setComponentFlag(Entity_ID entity, Component_ID component, bool value);
	const ComponentList getComponentList(Entity_ID entity) const;
private:
	std::vector<ComponentList> m_componentLists;
	Entity_ID m_lastNewEntity = 0;
	std::queue<Entity_ID> m_unusedEntityQueue;
};