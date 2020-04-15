#include "Entity.h"
#include "../Components/IComponent.h"
#include "../Attributes/AttributeManager.h"

void Entity::initComponents() {
	for (auto& comonent : m_components) {
		comonent->init();
	}
}

std::weak_ptr<AttributeManager> Entity::getAttributeManager() const {
	return m_attributes;
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
