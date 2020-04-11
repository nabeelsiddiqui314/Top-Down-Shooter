#pragma once
#include <memory>
#include "EntityManager.h"
#include "ComponentRegistry.h"
#include "SystemManager.h"
#include "ComponentIdGenerator.h"

class Entity {
public:
	Entity(Entity_ID entity, std::weak_ptr<EntityManager> entityManager, 
		std::weak_ptr<ComponentRegistry> componentRegistry, std::weak_ptr<SystemManager> systemManager);
	~Entity() = default;
public:
	template <typename T>
	bool hasComponent() {
		return m_componentRegistry.lock()->hasComponent(m_entityID);
	}

	template <typename T>
	void addComponent(const T& component) {
		Component_ID compID = ComponentIdGenerator::getUniqueID<T>();
		m_entityManager.lock()->setComponentFlag(m_entity_ID, compID, true);
		m_componentRegistry.lock()->addComponent(m_entityID, component);

		m_systemManager.lock()->notifyComponentChange(*this, m_entityManager.lock()->getComponentList());
	}

	template <typename T>
	T& getComponent() {
		return m_componentRegistry.lock()->getComponent(m_entityID);
	}

	Entity_ID getID() const;

	bool operator<(const Entity& entity) const;

	void remove();
private:
	Entity_ID m_entityID;
	std::weak_ptr<EntityManager> m_entityManager;
	std::weak_ptr<ComponentRegistry> m_componentRegistry;
	std::weak_ptr<SystemManager> m_systemManager;
};