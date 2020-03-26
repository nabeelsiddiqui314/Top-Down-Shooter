#include "DefaultEntityFactory.h"
#include "../Entity.h"
#include "../../Components/Transform.h"
#include "../../Components/Render.h"
#include "../../TransformBehaviours/UserInputMovement.h"

DefaultEntityFactory::DefaultEntityFactory(std::shared_ptr<sf::RenderWindow> window)
 : m_window(window) {}

std::shared_ptr<Entity> DefaultEntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();
	
	auto userInputBehaviour = std::make_shared<UserInputMovement>(100.0f);
	auto transformComp = std::make_shared<Transform>(player, userInputBehaviour);

	userInputBehaviour->setTransformComponent(transformComp);

	auto renderComp = std::make_shared<Render>(player, m_window, "player.png");

	player->registerComponent(transformComp);
	player->registerComponent(renderComp);

	return player;
}
