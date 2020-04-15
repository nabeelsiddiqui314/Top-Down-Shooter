#include "EntityFactory.h"
#include "Entity.h"
#include "../Attributes/TransformAttribute.h"
#include "../Attributes/SpriteAttribute.h"
#include "../Components/RenderComponent.h"
#include "../Attributes/AttributeManager.h"

EntityFactory::EntityFactory(std::shared_ptr<sf::RenderWindow> window, std::weak_ptr<EntityManager> entityManager)
 : m_window(window),
   m_entityManager(entityManager) {}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();
	auto attributes = player->getAttributeManager().lock();

	TransformAttribute transform;
	transform.position = {50, 50};
	transform.rotation = 0;

	attributes->addAttribue<TransformAttribute>(transform);
	attributes->addAttribue<SpriteAttribute>();

	player->addComponent<RenderComponent>(player->getAttributeManager(), "player.png", m_window);

	return player;
}
