#pragma once
#include <memory>
#include <vector>
#include "../Attributes/AttributeManager.h"

class IComponent;

class Entity {
	typedef std::unique_ptr<IComponent> ComponentPtr;
public:
	Entity();
	~Entity() = default;
public:
	void initComponents();

	template <typename T, typename... Args>
	void addComponent(Args&&... args) {
		m_components.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
		m_components.back()->initAttributes(m_attributes);
	}

	void update(float deltaTime);
	
	void destroy();
	bool shouldDestroy() const;
private:
	std::shared_ptr<AttributeManager> m_attributes;
	std::vector<ComponentPtr> m_components;
	bool m_shouldDestroy = false;
};