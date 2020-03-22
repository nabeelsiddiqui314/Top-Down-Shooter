#include "MenuState.h"
#include <iostream>
#include <string>
#include "StateMachine.h"
#include "GameState.h"
#include <SFML/Window/Event.hpp>


MenuState::MenuState() {
	std::cout << "Menu State" << std::endl;
}


MenuState::~MenuState() {

}

void MenuState::init(StateMachine* stateMachine) {
	
}

void MenuState::handleEvents(StateMachine * stateMachine, const sf::Event& evnt) {
	if (evnt.type == sf::Event::MouseButtonPressed) {
		stateMachine->setState<GameState>();
	}
}

void MenuState::update(StateMachine* stateMachine, float deltaTime) {

}

void MenuState::render(sf::RenderWindow& window) {

}