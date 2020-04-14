#include "Entity.h"
#include "../Events/Event.h"
#include "../Components/IComponent.h"
#include "EntityManager.h"

Entity::Entity(std::weak_ptr<EntityManager> entityManager) 
	: m_entityManager(entityManager) {}

void Entity::initComponents() {
	for (auto& comonent : m_components) {
		comonent->init();
	}
}

void Entity::dispatchEvent(Event& event) {
	for (auto& comonent : m_components) {
		event.dispatch(*comonent);
	}
}

void Entity::update(float deltaTime) {
	for	(auto& component : m_components) {
		component->update(deltaTime);
	}
}

std::weak_ptr<EntityManager> Entity::getEntityManager() const {
	return m_entityManager;
}

void Entity::destroy() {
	m_shouldDestroy = true;
}

bool Entity::shouldDestroy() const {
	return m_shouldDestroy;
}
