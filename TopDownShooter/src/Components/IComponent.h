#pragma once
#include <memory>
#include "../Events/IEventHandler.h"

class Entity;

class IComponent : public IEventHandler {
public:
	IComponent(const std::shared_ptr<Entity>& parent);
	virtual ~IComponent() {}
public:
	virtual void update(float deltaTime) = 0;
	const std::shared_ptr<Entity>& getParent() const;
private:
	std::shared_ptr<Entity> m_parent;
};