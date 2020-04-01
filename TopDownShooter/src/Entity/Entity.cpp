#include "Entity.h"
#include "../Events/Event.h"
#include "../Components/IComponent.h"
#include "EntityManager.h"
#include "../Components/TransformComponent.h"

Entity::Entity(std::weak_ptr<EntityManager> entityManager) 
	: m_entityManager(entityManager) {
	m_transformComponent = std::make_shared<TransformComponent>(weak_from_this());
	registerComponent(m_transformComponent);
}

Entity::Entity(std::weak_ptr<EntityManager> entityManager, float x, float y)
	: m_entityManager(entityManager) {
	m_transformComponent = std::make_shared<TransformComponent>(weak_from_this(), x, y);
	registerComponent(m_transformComponent);
}

void Entity::dispatchEvent(Event& event) {
	for (auto& comonent : m_components) {
		event.dispatch(*comonent);
	}
}

void Entity::registerComponent(const IComponentPtr component) {
	m_components.push_back(component);
}

void Entity::removeComponent(const IComponentPtr component) {
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

std::shared_ptr<TransformComponent> Entity::getTransformComponent() const {
	return m_transformComponent;
}

void Entity::destroy() {
	m_shouldDestroy = true;
}

bool Entity::shouldDestroy() const {
	return m_shouldDestroy;
}
