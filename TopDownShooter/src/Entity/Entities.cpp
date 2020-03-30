#include "Entities.h"
#include "Entity.h"

Entities::Entities(std::shared_ptr<sf::RenderWindow> window)
 : m_entityfactory(window) {}

void Entities::create() {
	m_entities.push_back(m_entityfactory.createPlayer()); // push back for copying since factory returns local pointer vars.
}

void Entities::update(float deltaTime) {
	for (auto entityIter = m_entities.begin(); entityIter != m_entities.end();) {
		auto& entity = *entityIter;

		if (!entity->shouldDestroy()) {
			entity->update(deltaTime);
			entityIter++;
		}
		else {
			entityIter = m_entities.erase(entityIter);
		}
	}

}