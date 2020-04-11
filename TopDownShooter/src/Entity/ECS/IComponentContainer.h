#pragma once
#include "EcsTypes.h"

class IComponentContainer {
public:
	IComponentContainer() = default;
	~IComponentContainer() = default;
public:
	virtual void removeEntity(Entity_ID entity) = 0;
};
