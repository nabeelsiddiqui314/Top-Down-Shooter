#include "ISystem.h"
#include "Entity.h"

void ISystem::addEntity(const Entity& entity) {
	m_entities.emplace(entity);
}

void ISystem::removeEntity(const Entity& entity) {
	m_entities.erase(entity);
}