#pragma once
#include <memory>

class AttributeManager;

class IComponent {
public:
	IComponent(std::weak_ptr<AttributeManager> attributes);
	virtual ~IComponent() {}
public:
	virtual void init() {};
	virtual void update(float deltaTime) = 0;
protected:
	std::weak_ptr<AttributeManager> m_attributes;
};