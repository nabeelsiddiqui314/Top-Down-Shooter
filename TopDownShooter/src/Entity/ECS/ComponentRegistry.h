#pragma once
#include <tuple>
#include "ComponentContainer.h"

template <typename... Components>
class ComponentRegistry {
public:
	ComponentRegistry() = default;
	~ComponentRegistry() = default;
public:
	template <typename T>
	bool hasComponent(Entity_ID entity) {
		auto& componentContainer = std::get<ComponentContainer<T>>(m_componentContainers);
		return componentContainer.hasComponent(entity);
	}

	template <typename T>
	void addComponent(Entity_ID entity, const T& component) {
		auto& componentContainer = std::get<ComponentContainer<T>>(m_componentContainers);
		componentContainer.addComponent(entity, component);
	}

	template <typename T>
	T& getComponent(Entity_ID entity) {
		auto& componentContainer = std::get<ComponentContainer<T>>(m_componentContainers);
		return componentContainer.getComponent(entity);
	}

	void removeEntity(Entity_ID entity) {
		removeEntityForEach(entity);
	}
private:
	template <std::size_t I = 0>
	void removeEntityForEach(Entity_ID entity) {
		auto& componentContainer = std::get<I>(m_componentContainers);
		componentContainer.removeEntity(entity);

		if constexpr (I + 1 != sizeof...(Components)) {
			removeEntityForEach<I + 1>(entity);
		}
	}

	Component_ID getNewID() const {
		static Component_ID ID { 0 };
		return ID++;
	}

	template <typename T>
	Component_ID getUniqueID() {
		static Component_ID ID { getNewID() };
		return ID;
	}
private:
	std::tuple<ComponentContainer<Components>...> m_componentContainers;
};