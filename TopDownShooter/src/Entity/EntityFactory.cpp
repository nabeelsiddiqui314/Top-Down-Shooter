#include "EntityFactory.h"
#include "Entity.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/ControllerComponent.h"
#include "../Components/GunComponent.h"

EntityFactory::EntityFactory(std::shared_ptr<sf::RenderWindow> window, std::weak_ptr<EntityManager> entityManager)
 : m_window(window),
   m_entityManager(entityManager) {}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>(m_entityManager);

	Animator::AnimationInfo animationInfo;
	animationInfo.width = 100;
	animationInfo.height = 100;
	animationInfo.columns = {4, 4, 4, 4};

	player->addComponent<TransformComponent>(player, 300, 400);
	player->addComponent<RenderComponent>(player, m_window, "player.png");
	player->addComponent<ControllerComponent>(player, m_window, 100);
	player->addComponent<GunComponent>(player, m_window, sf::Vector2f(74.0f, 14.0f));

	return player;
}
