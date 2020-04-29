#include "EntityFactory.h"
#include "Entity.h"
#include "../Components/RenderComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/InputComponent.h"
#include "../Commands/MoveCommand.h"

EntityFactory::EntityFactory(std::shared_ptr<SpriteSortRenderer> renderer, std::weak_ptr<EntityManager> entityManager)
 : m_renderer(renderer),
   m_entityManager(entityManager) {
	m_playerInputHandler = std::make_shared<InputHandler>();

	m_playerInputHandler->bind("move_up", sf::Keyboard::W);
	m_playerInputHandler->bind("move_down", sf::Keyboard::S);
	m_playerInputHandler->bind("move_left", sf::Keyboard::A);
	m_playerInputHandler->bind("move_right", sf::Keyboard::D);
}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();

	player->addComponent<TransformComponent>(0, 0, 4.0f, 4.0f);
	player->addComponent<RenderComponent>("player.png", m_renderer);

	auto moveComp = player->addComponent<MovementComponent>(100.0f);
	auto inputComp = player->addComponent<InputComponent>(m_playerInputHandler);

	inputComp->bindCommand("move_up"   , std::make_unique<MoveCommand>(moveComp, Direction::UP));
	inputComp->bindCommand("move_down" , std::make_unique<MoveCommand>(moveComp, Direction::DOWN));
	inputComp->bindCommand("move_left" , std::make_unique<MoveCommand>(moveComp, Direction::LEFT));
	inputComp->bindCommand("move_right", std::make_unique<MoveCommand>(moveComp, Direction::RIGHT));

	return player;
}

std::shared_ptr<Entity> EntityFactory::createStaticObject(const std::string& name, float x, float y) const {
	auto obj = std::make_shared<Entity>();

	obj->addComponent<TransformComponent>(x, y, 0.6f, 0.6f);
	obj->addComponent<RenderComponent>(name + ".png", m_renderer);

	return obj;
}
