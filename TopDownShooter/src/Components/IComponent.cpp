#include "IComponent.h"

IComponent::IComponent(std::unique_ptr<IEventHandler>&& eventHandler) 
 : m_eventHandler(std::move(eventHandler)) {}

const std::unique_ptr<IEventHandler>& IComponent::getEventHandler() const {
	return m_eventHandler;
}