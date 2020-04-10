#pragma once
#include <array>
#include <unordered_map>
#include <cassert>
#include "IComponentContainer.h"
#include "EcsTypes.h"

template <typename T>
class ComponentContainer : public IComponentContainer {
public:
	ComponentContainer(ECS_Events& events) {
		events.subscribe<EntityDestroyedEvent>([&](const auto& event) {
			removeEntity(event.entity);
		});
	}
	~ComponentContainer() = default;
public:
	void addComponent(Entity_ID entity, const T& component) {
		assert(!hasComponent(entity));

		std::size_t index = ++m_lastComponentIndex;
		m_entityToIndexMap[entity] = index;
		m_indexToEntityMap[index] = entity;

		m_componentArray[index] = component;
	}

	void removeEntity(Entity_ID entity) {
		if (hasComponent(entity)) {
			std::size_t replacementIndex = m_entityToIndexMap.at(entity);
			m_componentArray[replacementIndex] = m_componentArray[m_lastComponentIndex];

			Entity_ID LastElementEntity = m_indexToEntityMap[m_lastComponentIndex];
			m_entityToIndexMap[LastElementEntity] = replacementIndex;
			m_indexToEntityMap[replacementIndex] = LastElementEntity;

			m_entityToIndexMap.erase(entity);
			m_indexToEntityMap.erase(m_lastComponentIndex);

			m_lastComponentIndex--;
		}
	}

	bool hasComponent(Entity_ID entity) {
		return m_entityToIndexMap.find(entity) != m_entityToIndexMap.end();
	}

	T& getComponent(Entity_ID entity) {
		assert(hasComponent(entity), "Trying to access a component that the entity does not possess");
		return m_componentArray[m_entityToIndexMap[entity]];
	}
private:
	std::array<T, COMPONENTS_LIMIT> m_componentArray;
	std::unordered_map<Entity_ID, std::size_t> m_entityToIndexMap;
	std::unordered_map<std::size_t, Entity_ID> m_indexToEntityMap;
	std::size_t m_lastComponentIndex = 0;
};