#include "IComponent.h"
#include "../Core/Entity.h"

IComponent::IComponent(std::weak_ptr<Entity> parent)
 :  m_parent(parent) {}

void IComponent::dispatchEventToParent(Event& event) {
	auto parent = m_parent.lock();
	if (parent) {
		parent->dispatchEvent(event);
	}
}