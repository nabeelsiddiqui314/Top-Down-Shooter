#pragma once
#include <vector>
#include <memory>

class Entity;
class IEntityFactory;

class Entities {
private:
	typedef std::shared_ptr<Entity> EntityPtr;
public:
	Entities(std::unique_ptr<IEntityFactory>&& entityfactory);
	~Entities() = default;
public:
	void create();
	void update(float deltaTime);
private:
	std::unique_ptr<IEntityFactory> m_entityfactory;
	std::vector<EntityPtr> m_entities;
};