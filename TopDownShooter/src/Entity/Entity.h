#pragma once
#include "../Attributes/AttributeManager.h"

class Event;
class EntityManager;
class IComponent;

class Entity {
	typedef std::unique_ptr<IComponent> ComponentPtr;
public:
	Entity(std::weak_ptr<EntityManager> entityManager);
	~Entity() = default;
public:
	void initComponents();
	void dispatchEvent(Event& event);

	template <typename T, typename... Args>
	void addComponent(Args&&... args) {
		m_components.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
	}

	template <typename T, typename... Args>
	void addAttribute(Args&&... args) {
		m_attributes->addAttribue<T>(std::make_shared<T>(std::forward<Args>(args)...));
	}

	void update(float deltaTime);
	
	std::weak_ptr<EntityManager> getEntityManager() const;
	void destroy();
	bool shouldDestroy() const;
private:
	
private:
	std::shared_ptr<AttributeManager> m_attributes;
	std::weak_ptr<EntityManager> m_entityManager;
	std::vector<ComponentPtr> m_components;
	bool m_shouldDestroy = false;
};