#include "GameState.h"
#include "StateMachine.h"
#include "MenuState.h"
#include <SFML/Window/Event.hpp>
#include "../Entity/Entities.h"
#include "../Utilities/InputHandler.h"

GameState::GameState() {
	auto& inputHandler = InputHandler::getInstance();
	inputHandler.bind("move_up",    sf::Keyboard::W);
	inputHandler.bind("move_down",  sf::Keyboard::S);
	inputHandler.bind("move_left",  sf::Keyboard::A);
	inputHandler.bind("move_right", sf::Keyboard::D);
}


GameState::~GameState() {

}

void GameState::init(StateMachine* stateMachine) {
	m_entities = std::make_unique<Entities>();
	m_entities->create();
}

void GameState::handleEvents(StateMachine* stateMachine, const sf::Event& evnt) {
	
}

void GameState::update(StateMachine* stateMachine, float deltaTime) {
	m_entities->update(deltaTime);
}

void GameState::render(sf::RenderWindow& window) {
	m_entities->render(window);
}