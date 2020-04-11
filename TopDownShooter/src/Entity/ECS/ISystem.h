#pragma once
#include <set>

class Entity;

class ISystem {
public:
	ISystem() = default;
	~ISystem() = default;
private:
	using SystemEntities = std::set<Entity>;
public:
	virtual void update(float deltaTime) = 0;

	void addEntity(const Entity& entity);
	void removeEntity(const Entity& entity);
protected:
	SystemEntities m_entities;
};