#include "MenuState.h"
#include "StateMachine.h"
#include "GameState.h"
#include <SFML/Window/Event.hpp>


MenuState::MenuState() {
	
}


MenuState::~MenuState() {

}

void MenuState::init(StateMachine* stateMachine) {
	
}

void MenuState::handleEvents(StateMachine* stateMachine, const sf::Event& evnt) {
	if (evnt.type == sf::Event::KeyReleased && evnt.key.code == sf::Keyboard::Enter) {
		stateMachine->setState<GameState>();
	}
}

void MenuState::update(StateMachine* stateMachine, float deltaTime) {

}

void MenuState::render(sf::RenderWindow& window) {

}