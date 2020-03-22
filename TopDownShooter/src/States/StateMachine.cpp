#include "StateMachine.h"

void StateMachine::handleEvents(const sf::Event& evnt) {
	m_currentState->handleEvents(this, evnt);
}

void StateMachine::update(float deltaTime) {
	m_currentState->update(this, deltaTime);
}

void StateMachine::render(sf::RenderWindow& window) {
	m_currentState->render(window);
}