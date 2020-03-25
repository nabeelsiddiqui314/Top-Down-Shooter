#pragma once
#include <memory>
#include "../Events/IEventHandler.h"

class Entity;

class IComponent : public IEventHandler {
public:
	IComponent(std::weak_ptr<Entity> parent);
	virtual ~IComponent() {}
public:
	virtual void update(float deltaTime) = 0;
	void dispatchEventToParent(Event& event);
private:
	std::weak_ptr<Entity> m_parent;
};