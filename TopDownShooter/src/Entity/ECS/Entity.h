#pragma once
#include <memory>
#include "ComponentRegistry.h"

class Entity {
public:
	Entity(Entity_ID entity, std::weak_ptr<ComponentRegistry> componentRegistry);
	~Entity() = default;
public:
	template <typename T>
	bool hasComponent() {
		return m_componentRegistry.lock()->hasComponent();
	}

	template <typename T>
	void addComponent(const T& component) {
		m_componentRegistry.lock()->addComponent();
	}

	template <typename T>
	T& getComponent() {
		return m_componentRegistry.lock()->getComponent();
	}

	bool operator<(const Entity& entity) const;

	void remove();
private:
	std::weak_ptr<ComponentRegistry> m_componentRegistry;
	Entity_ID m_entityID;
};