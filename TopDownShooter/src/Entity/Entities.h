#pragma once
#include <vector>
#include <memory>
#include "EntityManager.h"
#include "EntityFactory.h"
#include "../Utilities/SpriteSortRenderer.h"

class Entity;

class Entities {
public:
	Entities();
	~Entities() = default;
public:
	void create();
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
private:
	std::shared_ptr<SpriteSortRenderer> m_spriteRenderer;
	std::shared_ptr<EntityManager> m_entityManager;
	EntityFactory m_entityfactory;
};