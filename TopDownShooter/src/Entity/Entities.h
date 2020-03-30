#pragma once
#include <vector>
#include <memory>
#include "EntityFactory.h"

class Entity;

class Entities {
private:
	typedef std::shared_ptr<Entity> EntityPtr;
public:
	Entities(std::shared_ptr<sf::RenderWindow> window);
	~Entities() = default;
public:
	void create();
	void update(float deltaTime);
private:
	EntityFactory m_entityfactory;
	std::vector<EntityPtr> m_entities;
};