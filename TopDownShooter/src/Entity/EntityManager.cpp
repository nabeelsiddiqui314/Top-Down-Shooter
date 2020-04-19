#include "EntityManager.h"
#include "Entity.h"
#include <algorithm>

void EntityManager::addEntity(std::shared_ptr<Entity> entity) {
	entity->initComponents();
	m_entities.push_back(entity);
}

void EntityManager::update(float deltaTime) {
	for (std::size_t i = 0; i < m_entities.size(); i++) {
		if (!m_entities[i]->shouldDestroy()) {
			m_entities[i]->update(deltaTime);
		}
		else {
			m_entities.erase(m_entities.begin() + i);
		}
	}
}