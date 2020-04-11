#include "ComponentRegistry.h"

void ComponentRegistry::removeEntity(Entity_ID entity) {
	for (auto& componentContainer : m_componentIndexMap) {
		componentContainer.second->removeEntity(entity);
	}
}