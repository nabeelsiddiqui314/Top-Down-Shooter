#include "EntityManager.h"
#include "Entity.h"

void EntityManager::addEntity(std::shared_ptr<Entity> entity) {
	m_entities.push_back(entity);
}

void EntityManager::update(float deltaTime) {
	for (auto entityIter = m_entities.begin(); entityIter != m_entities.end();) {
		auto& entity = *entityIter;

		if (!entity->shouldDestroy()) {
			entity->update(deltaTime);
			entityIter++;
		}
		else {
			entityIter = m_entities.erase(entityIter);
		}
	}
}