#include "DefaultEntityFactory.h"
#include "../Entity.h"
#include "../../Components/TransformComponent.h"
#include "../../Components/RenderComponent.h"
#include "../../Components/AnimationComponent.h"
#include "../../Components/ControllerComponent.h"

DefaultEntityFactory::DefaultEntityFactory(std::shared_ptr<sf::RenderWindow> window)
 : m_window(window) {}

std::shared_ptr<Entity> DefaultEntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();
	
	auto transformComp = std::make_shared<TransformComponent>(player);
	auto renderComp = std::make_shared<RenderComponent>(player, m_window, "player.png");

	Animator::AnimationInfo animationInfo;
	animationInfo.width = 100;
	animationInfo.height = 100;
	animationInfo.columns = {4, 4, 4, 4};

	auto animationComp = std::make_shared<AnimationComponent>(player, animationInfo);
	auto controllerComp = std::make_shared<ControllerComponent>(player, 100);


	player->registerComponent(transformComp);
	player->registerComponent(renderComp);
	player->registerComponent(animationComp);
	player->registerComponent(controllerComp);

	return player;
}
