#include "Entity.h"
#include "../Components/IComponent.h"
#include "../Events/EntityEventManager.h"

Entity::Entity() {
	m_attributes = std::make_shared<AttributeManager>();
	m_eventManager = std::make_shared<EntityEventManager>();
}

void Entity::initComponents() {
	for (auto& comonent : m_components) {
		comonent->fetchAttributes(m_attributes);
	}
}

void Entity::update(float deltaTime) {
	for	(auto& component : m_components) {
		component->update(deltaTime);
	}
}

void Entity::destroy() {
	m_shouldDestroy = true;
}

bool Entity::shouldDestroy() const {
	return m_shouldDestroy;
}
