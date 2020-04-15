#pragma once
#include <memory>
#include "../Events/IEventHandler.h"

class AttributeManager;

class IComponent : public IEventHandler {
public:
	IComponent(std::weak_ptr<AttributeManager> attributes);
	virtual ~IComponent() {}
public:
	virtual void init() {};
	virtual void update(float deltaTime) = 0;
protected:
	std::weak_ptr<AttributeManager> m_attributes;
};