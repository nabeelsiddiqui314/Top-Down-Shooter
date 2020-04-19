#include "EntityFactory.h"
#include "Entity.h"
#include "../Components/RenderComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"

EntityFactory::EntityFactory(std::shared_ptr<sf::RenderWindow> window, std::weak_ptr<EntityManager> entityManager)
 : m_window(window),
   m_entityManager(entityManager) {}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();

	Animator::AnimationInfo animInfo;
	animInfo.width = 20;
	animInfo.height = 20;
	animInfo.columns = { 10, 10, 10};

	player->addComponent<MovementComponent>(20.0f);
	player->addComponent<AnimationComponent>(animInfo);
	player->addComponent<RenderComponent>("player.png", m_window);
	player->addComponent<TransformComponent>(0, 0);

	return player;
}
