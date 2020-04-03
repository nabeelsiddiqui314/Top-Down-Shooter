#pragma once
#include <memory>

class Entity;

class ISubSystem {
public:
	ISubSystem() {}
	virtual ~ISubSystem() {}
public:
	virtual void extractComponents(std::weak_ptr<Entity>) = 0;
	virtual void update(float deltaTime) = 0;
};