#include "Entity.h"
#include "Events/Event.h"
#include "Components/IComponent.h"

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