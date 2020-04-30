#include "EntityFactory.h"
#include "Entity.h"
#include "../Components/RenderComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/InputComponent.h"
#include "../Commands/MoveCommand.h"
#include "../Components/CameraComponent.h"

EntityFactory::EntityFactory(std::shared_ptr<SpriteSortRenderer> renderer, std::shared_ptr<Camera> camera)
 : m_renderer(renderer),
	m_camera(camera) {}

std::shared_ptr<Entity> EntityFactory::createPlayer() const {
	auto player = std::make_shared<Entity>();

	player->addComponent<TransformComponent>(0, 0, 4.0f, 4.0f);
	player->addComponent<RenderComponent>("player.png", m_renderer);
	player->addComponent<CameraComponent>(m_camera);

	auto moveComp = player->addComponent<MovementComponent>(100.0f);
	auto inputComp = player->addComponent<InputComponent>();

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
