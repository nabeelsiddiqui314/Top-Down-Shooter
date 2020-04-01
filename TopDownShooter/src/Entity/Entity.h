#pragma once
#include <memory>
#include <vector>
#include <bitset>
#include <array>
#include <type_traits>

class Event;
class EntityManager;
class IComponent;

class Entity {
	typedef std::shared_ptr<IComponent> IComponentPtr;
	typedef std::bitset<16> ComponentBitset;
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

		if (!m_componentBitset[componentID]) {
			m_componentBitset[componentID] = true;
			auto component = std::make_shared<T>(std::forward<Args>(args)...);
			m_components.push_back(component);
		}
	}

	template <typename T>
	bool hasComponent() {
		auto componentID = getComponentID<T>();
		return m_componentBitset[componentID];
	}

	template <typename T>
	std::weak_ptr<T> getComponent() {
		auto componentID = getComponentID<T>();
		return std::static_pointer_cast<T>(m_components[componentID]);
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
	ComponentBitset m_componentBitset;
	std::weak_ptr<EntityManager> m_entityManager;
	bool m_shouldDestroy = false;
};