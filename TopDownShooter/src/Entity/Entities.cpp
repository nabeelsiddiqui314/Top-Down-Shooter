#include "Entities.h"
#include "Entity.h"

Entities::Entities(std::shared_ptr<sf::RenderWindow> window)
 : m_entityfactory(window) {}

void Entities::create() {
	m_entityManager.addEntity(m_entityfactory.createPlayer());
}

void Entities::update(float deltaTime) {
	m_entityManager.update(deltaTime);

}