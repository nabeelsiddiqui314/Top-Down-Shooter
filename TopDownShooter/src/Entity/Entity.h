#pragma once
#include <memory>
#include <vector>
#include <array>
#include <type_traits>
#include <unordered_map>
#include <cassert>

class Event;
class EntityManager;
class IComponent;

class Entity {
	typedef std::shared_ptr<IComponent> IComponentPtr;
	typedef std::size_t ComponentID;
public:
	Entity(std::weak_ptr<EntityManager> entityManager);
	~Entity() = default;
public:
	void initComponents();
	void dispatchEvent(Event& event);

	template <typename T, typename... Args>
	void addComponent(Args&&... args) {		
		auto componentID = getComponentID<T>();

		if (!hasComponent<T>()) {
			auto component = std::make_shared<T>(std::forward<Args>(args)...);
			m_componentIndexMap.emplace(std::make_pair(componentID, m_components.size()));
			m_components.push_back(component);
		}
	}

	template <typename T>
	bool hasComponent() {
		auto componentID = getComponentID<T>();
		return m_componentIndexMap.find(componentID) != m_componentIndexMap.end();
	}

	template <typename T>
	std::weak_ptr<T> getComponent() {
		auto componentID = getComponentID<T>();
		assert(hasComponent<T>(), "Trying to fetch invalid component");
		return std::static_pointer_cast<T>(m_components[m_componentIndexMap.at(componentID)]);
	}

	void update(float deltaTime);
	
	std::weak_ptr<EntityManager> getEntityManager() const;
	void destroy();
	bool shouldDestroy() const;
private:
	ComponentID generateComponentID() {
		static ComponentID ID { 0 };
		return ID++;
	}

	template <typename T>
	ComponentID getComponentID() {
		static_assert(std::is_base_of<IComponent, T>::value, "Invalid Type: It is not a component!");
		static ComponentID ID { generateComponentID() };
		return ID;
	}
private:
	std::vector<IComponentPtr> m_components;
	std::unordered_map<ComponentID, std::size_t> m_componentIndexMap;
	std::weak_ptr<EntityManager> m_entityManager;
	bool m_shouldDestroy = false;
};