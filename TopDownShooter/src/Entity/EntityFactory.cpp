#include "EntityFactory.h"
#include "Entity.h"
#include "../Components/IComponent.h"

EntityFactory::EntityFactory(std::shared_ptr<sf::RenderWindow> window, std::weak_ptr<EntityManager> entityManager)
 : m_window(window),
   m_entityManager(entityManager) {}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();

	return player;
}
