#include "GameState.h"
#include "StateMachine.h"
#include "MenuState.h"
#include <SFML/Window/Event.hpp>
#include "../Entity/Entities.h"


GameState::GameState() {
	
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