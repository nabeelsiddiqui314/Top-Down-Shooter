#include "IComponent.h"

IComponent::IComponent(const std::shared_ptr<Entity>& parent, std::unique_ptr<IEventHandler>&& eventHandler)
 :  m_parent(parent),
	m_eventHandler(std::move(eventHandler)) {}

const std::unique_ptr<IEventHandler>& IComponent::getEventHandler() const {
	return m_eventHandler;
}

const std::shared_ptr<Entity>& IComponent::getParent() const {
	return m_parent;
}