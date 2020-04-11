#pragma once
#include <memory>

class Entity;

class IBlueprint {
public:
	IBlueprint() = default;
	virtual ~IBlueprint() {}
public:
	virtual std::shared_ptr<Entity> getEntity() = 0;
};