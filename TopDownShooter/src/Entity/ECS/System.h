#pragma once
#include <set>

class Entity;

class System {
public:
	System() = default;
	~System() = default;
private:
	using SystemEntities = std::set<Entity>;
public:
	virtual void update(float deltaTime) = 0;

	void addEntity(const Entity& entity);
	void removeEntity(Entity& entity);
protected:
	SystemEntities m_entities;
};