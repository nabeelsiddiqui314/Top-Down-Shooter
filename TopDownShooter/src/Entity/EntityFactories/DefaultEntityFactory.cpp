#include "DefaultEntityFactory.h"
#include "../Entity.h"
#include "../../Components/Transform.h"
#include "../../Components/Render.h"
#include "../../Components/Animation.h"

DefaultEntityFactory::DefaultEntityFactory(std::shared_ptr<sf::RenderWindow> window)
 : m_window(window) {}

std::shared_ptr<Entity> DefaultEntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();
	
	auto transformComp = std::make_shared<Transform>(player);
	auto renderComp = std::make_shared<Render>(player, m_window, "player.png");

	Animator::AnimationInfo animationInfo;
	animationInfo.width = 100;
	animationInfo.height = 100;
	animationInfo.columns = {4, 4, 4, 4};

	auto animationComp = std::make_shared<Animation>(player, animationInfo);

	player->registerComponent(transformComp);
	player->registerComponent(renderComp);
	player->registerComponent(animationComp);

	return player;
}
