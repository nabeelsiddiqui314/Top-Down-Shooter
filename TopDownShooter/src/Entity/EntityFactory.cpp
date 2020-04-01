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
	auto player = std::make_shared<Entity>(m_entityManager, 300, 400);
	
	auto renderComp = std::make_shared<RenderComponent>(player, m_window, "player.png");

	Animator::AnimationInfo animationInfo;
	animationInfo.width = 100;
	animationInfo.height = 100;
	animationInfo.columns = {4, 4, 4, 4};

	auto animationComp = std::make_shared<AnimationComponent>(player, animationInfo);
	auto controllerComp = std::make_shared<ControllerComponent>(player, 100);
	auto gunComp = std::make_shared<GunComponent>(player, m_window);

	player->registerComponent(renderComp);
	player->registerComponent(animationComp);
	player->registerComponent(controllerComp);
	player->registerComponent(gunComp);

	return player;
}
