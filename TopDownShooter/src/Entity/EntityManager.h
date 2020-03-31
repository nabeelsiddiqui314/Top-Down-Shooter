#pragma once
#include <memory>
#include <vector>

class Entity;

class EntityManager {
private:
	typedef std::shared_ptr<Entity> EntityPtr;
public:
	EntityManager() = default;
	~EntityManager() = default;
public:
	void addEntity(std::shared_ptr<Entity> entity);
	
	void update(float deltaTime);
private:
	std::vector<EntityPtr> m_entities;
};