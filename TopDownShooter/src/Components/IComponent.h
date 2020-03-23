#pragma once
#include <memory>
#include "../Events/IEventHandler.h"

class IComponent {
public:
	IComponent(std::unique_ptr<IEventHandler>&& eventHandler);
	virtual ~IComponent() {}
public:
	virtual void update(float deltaTime) = 0;
	const std::unique_ptr<IEventHandler>& getEventHandler() const;
private:
	std::unique_ptr<IEventHandler> m_eventHandler;
};