#include "ComponentRegistry.h"

ComponentRegistry::ComponentRegistry(ECS_Events& events) 
 : m_events(events) {}

void ComponentRegistry::removeEntity(Entity_ID entity) {
	m_events.publish<EntityDestroyedEvent>({ entity });
}