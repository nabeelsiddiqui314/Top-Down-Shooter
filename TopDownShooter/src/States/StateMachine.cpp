#include "StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>

StateMachine::StateMachine(std::shared_ptr<sf::RenderWindow> window)
: m_window(window) {}

void StateMachine::handleEvents(const sf::Event& evnt) {
	m_currentState->handleEvents(this, evnt);
}

void StateMachine::update(float deltaTime) {
	m_currentState->update(this, deltaTime);
}

void StateMachine::render() {
	m_currentState->render(*m_window);
}

std::shared_ptr<sf::RenderWindow> StateMachine::getWindow() const {
	return m_window;
}