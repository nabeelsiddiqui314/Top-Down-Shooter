#pragma once
#include <memory>
#include <unordered_map>
#include "ComponentIdGenerator.h"
#include "EcsTypes.h"
#include "ComponentContainer.h"

class ComponentRegistry {
public:
	ComponentRegistry() = default;
	~ComponentRegistry() = default;
public:
	template <typename T>
	void registerComponent() {
		Component_ID compID = ComponentIdGenerator::getUniqueID<T>();
		m_componentIndexMap.emplace(std::make_pair(compID, std::make_shared<ComponentContainer<T>>(m_events)));
	}

	template <typename T>
	bool hasComponent(Entity_ID entity) {
		return getComponentContainer<T>()->hasComponent(entity);
	}

	template <typename T>
	void addComponent(Entity_ID entity, const T& component) {
		getComponentContainer<T>()->addComponent(entity, component);
	}

	template <typename T>
	T& getComponent(Entity_ID entity) {
		return getComponentContainer<T>()->getComponent(entity);
	}

	void removeEntity(Entity_ID entity);
private:
	template <typename T>
	std::shared_ptr<ComponentContainer<T>> getComponentContainer() {
		Component_ID compID = ComponentIdGenerator::getUniqueID<T>();
		assert(m_componentIndexMap.find(compID) != m_componentIndexMap.end() && "Trying to access an unregistered component!");

		return std::static_pointer_cast<ComponentContainer<T>>(m_componentIndexMap.at(compID));
	}
private:
	std::unordered_map<Component_ID, std::shared_ptr<IComponentContainer>> m_componentIndexMap;
};