#pragma once
#include <memory>
#include <vector>
#include "../Attributes/AttributeManager.h"

class IComponent;

class Entity {
	typedef std::shared_ptr<IComponent> ComponentPtr;
public:
	Entity();
	~Entity() = default;
public:
	void initComponents();

	template <typename T, typename... Args>
	std::shared_ptr<T> addComponent(Args&&... args) {
		auto component = std::make_shared<T>(std::forward<Args>(args)...);
		m_components.emplace_back(component);
		m_components.back()->initAttributes(m_attributes);
		return component;
	}

	void update(float deltaTime);
	
	void destroy();
	bool shouldDestroy() const;
private:
	std::shared_ptr<AttributeManager> m_attributes;
	std::vector<ComponentPtr> m_components;
	bool m_shouldDestroy = false;
};