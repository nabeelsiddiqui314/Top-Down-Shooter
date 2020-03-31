#include "Entity.h"
#include "../Events/Event.h"
#include "../Components/IComponent.h"
#include "EntityManager.h"

Entity::Entity(std::weak_ptr<EntityManager> entityManager) 
: m_entityManager(entityManager) {}

void Entity::dispatchEvent(Event& event) {
	for (auto& comonent : m_components) {
		event.dispatch(*comonent);
	}
}

void Entity::registerComponent(const IComponentPtr& component) {
	m_components.emplace_back(component);
}

void Entity::removeComponent(const IComponentPtr& component) {
	auto componentIterator = std::find(m_components.begin(), m_components.end(), component);
	if (componentIterator != m_components.end()) {
		m_components.erase(componentIterator);
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
