#include "GameState.h"
#include "StateMachine.h"
#include "MenuState.h"
#include <SFML/Window/Event.hpp>
#include "../Entity/Entities.h"
#include "../Entity/EntityFactories/DefaultEntityFactory.h"


GameState::GameState() {
	
}


GameState::~GameState() {

}

void GameState::init(StateMachine* stateMachine) {
	m_entities = std::make_unique<Entities>(std::make_unique<DefaultEntityFactory>(stateMachine->getWindow()));
	m_entities->create();
}

void GameState::handleEvents(StateMachine* stateMachine, const sf::Event& evnt) {
	
}

void GameState::update(StateMachine* stateMachine, float deltaTime) {
	m_entities->update(deltaTime);
}

void GameState::render(sf::RenderWindow& window) {

}