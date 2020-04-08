#pragma once
#include <vector>
#include <memory>
#include "EntityFactory.h"

class Entity;

class Entities {
public:
	Entities() = default;
	~Entities() = default;
public:
	void create();
	void update(float deltaTime);
private:
	EntityFactory m_entityfactory;
};