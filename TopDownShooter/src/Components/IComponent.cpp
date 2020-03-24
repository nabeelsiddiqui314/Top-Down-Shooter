#include "IComponent.h"

IComponent::IComponent(const std::shared_ptr<Entity>& parent)
 :  m_parent(parent) {}

const std::shared_ptr<Entity>& IComponent::getParent() const {
	return m_parent;
}