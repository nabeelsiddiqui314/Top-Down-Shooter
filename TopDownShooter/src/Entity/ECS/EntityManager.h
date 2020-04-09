#pragma once
#include <vector>
#include <queue>
#include "EcsTypes.h"

class EntityManger {
public:
	EntityManger() = default;
	~EntityManger() = default;
public:
	Entity_ID createEntity();
	void destroyEntity(Entity_ID entity);
	
	void setComponentFlag(Entity_ID entity, Component_ID component, bool value);
	const ComponentBitset getComponentBitmask(Entity_ID entity) const;
private:
	std::vector<ComponentBitset> m_componentBitsets;
	Entity_ID m_lastNewEntity = 0;
	std::queue<Entity_ID> m_unusedEntityQueue;
};