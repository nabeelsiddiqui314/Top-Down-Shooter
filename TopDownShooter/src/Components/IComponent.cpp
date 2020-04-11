#include "IComponent.h"
#include "../Entity/Blueprints/IBlueprint.h"
#include "../Entity/EntityManager.h"

IComponent::IComponent(std::weak_ptr<Entity> parent)
 :  m_parent(parent) {}

void IComponent::dispatchEventToParent(Event& event) {
	auto parent = m_parent.lock();
	if (parent) {
		parent->dispatchEvent(event);
	}
}

void IComponent::destroyParent() {
	auto parent = m_parent.lock();
	if (parent) {
		parent->destroy();
	}
}

void IComponent::addEntityFromBlueprint(std::unique_ptr<IBlueprint>& bluePrint) {
	auto parent = m_parent.lock();
	if (parent) {
		auto entityManager = parent->getEntityManager().lock();
		entityManager->addEntity(bluePrint->getEntity());
	}
}