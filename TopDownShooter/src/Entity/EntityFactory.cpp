#include "EntityFactory.h"
#include "Entity.h"
#include "../Attributes/TransformAttribute.h"
#include "../Attributes/SpriteAttribute.h"
#include "../Components/RenderComponent.h"
#include "../Attributes/AnimationAttribute.h"
#include "../Attributes/AttributeManager.h"
#include "../Components/AnimationComponent.h"

EntityFactory::EntityFactory(std::shared_ptr<sf::RenderWindow> window, std::weak_ptr<EntityManager> entityManager)
 : m_window(window),
   m_entityManager(entityManager) {}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();
	auto attributes = player->getAttributeManager().lock();

	TransformAttribute transform;
	transform.position = {50, 50};
	transform.rotation = 0;

	AnimationAttribute animation;
	animation.row = 2;
	animation.column = 3;
	animation.interval = 0.8f;
	animation.isAnimating = true;

	Animator::AnimationInfo animInfo;
	animInfo.width = 20;
	animInfo.height = 20;
	animInfo.columns = { 10, 10, 10};

	attributes->addAttribue<TransformAttribute>(transform);
	attributes->addAttribue<SpriteAttribute>();
	attributes->addAttribue<AnimationAttribute>(animation);

	player->addComponent<AnimationComponent>(player->getAttributeManager(), animInfo);
	player->addComponent<RenderComponent>(player->getAttributeManager(), "player.png", m_window);

	return player;
}
