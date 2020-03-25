#include "MenuState.h"
#include "StateMachine.h"
#include "GameState.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Resources/ResourceManager.h"


MenuState::MenuState() {
	
}

MenuState::~MenuState() {
	
}

void MenuState::init(StateMachine* stateMachine) {
	m_title.setString("Top-Down Shooter! (Press Enter to continue)"); //temporary

	auto& resourceManager = ResourceManager::getInstance();
	m_font = resourceManager.fontContainer.aquire("thinPix.ttf");
	resourceManager.fontContainer.freeOrphanResources();

	m_title.setFont(*m_font);
	m_title.setPosition(0, 0);
	m_title.setFillColor(sf::Color::White);
}

void MenuState::handleEvents(StateMachine* stateMachine, const sf::Event& evnt) {
	if (evnt.type == sf::Event::KeyReleased && evnt.key.code == sf::Keyboard::Enter) {
		stateMachine->setState<GameState>();
	}
}

void MenuState::update(StateMachine* stateMachine, float deltaTime) {

}

void MenuState::render(sf::RenderWindow& window) {
	window.draw(m_title);
}