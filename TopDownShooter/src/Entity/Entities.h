#pragma once
#include <vector>
#include <memory>
#include "EntityManager.h"
#include "EntityFactory.h"

class Entity;

class Entities {
public:
	Entities(std::shared_ptr<sf::RenderWindow> window);
	~Entities() = default;
public:
	void create();
	void update(float deltaTime);
private:
	std::shared_ptr<EntityManager> m_entityManager;
	EntityFactory m_entityfactory;
};