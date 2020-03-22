#include "GameState.h"
#include <iostream>
#include <string>
#include "StateMachine.h"
#include "MenuState.h"
#include <SFML/Window/Event.hpp>


GameState::GameState() {
	std::cout << "Game State" << std::endl;
}


GameState::~GameState() {

}

void GameState::init(StateMachine* stateMachine) {
	
}

void GameState::handleEvents(StateMachine* stateMachine, const sf::Event& evnt) {
	if (evnt.type == sf::Event::KeyReleased) {
		stateMachine->setState<MenuState>();
	}
}

void GameState::update(StateMachine* stateMachine, float deltaTime) {
	
}

void GameState::render(sf::RenderWindow& window) {

}