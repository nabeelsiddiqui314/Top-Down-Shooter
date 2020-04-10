#include "System.h"
#include "Entity.h"

void System::addEntity(const Entity& entity) {
	m_entities.emplace(entity);
}

void System::removeEntity(Entity& entity) {
	entity.remove();
	m_entities.erase(entity);
}