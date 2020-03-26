#include "Entities.h"
#include "Entity.h"
#include "IEntityFactory.h"

Entities::Entities(std::unique_ptr<IEntityFactory>&& entityfactory) 
 : m_entityfactory(std::move(entityfactory)) {}

void Entities::create() {
	m_entities.push_back(m_entityfactory->createPlayer()); // push back for copying since factory returns local pointer vars.
}

void Entities::update(float deltaTime) {
	for (auto& entity : m_entities) {
		entity->update(deltaTime);
	}
}