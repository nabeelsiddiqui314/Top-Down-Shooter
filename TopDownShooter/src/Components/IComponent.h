#pragma once
#include <memory>
#include "../Events/IEventHandler.h"

class Entity;

class IComponent {
public:
	IComponent(const std::shared_ptr<Entity>& parent, std::unique_ptr<IEventHandler>&& eventHandler);
	virtual ~IComponent() {}
public:
	virtual void update(float deltaTime) = 0;
	const std::unique_ptr<IEventHandler>& getEventHandler() const;
	const std::shared_ptr<Entity>& getParent() const;
private:
	std::shared_ptr<Entity> m_parent;
	std::unique_ptr<IEventHandler> m_eventHandler;
};