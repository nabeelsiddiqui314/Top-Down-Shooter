#include "Application.h"
#include <SFML/Window/Event.hpp>
#include "States/MenuState.h"

Application::Application(std::uint16_t windowWidth, std::uint16_t windowHeight, const std::string& title) {
	m_window.create(sf::VideoMode(windowWidth, windowHeight), title);
	m_stateMachine.setState<MenuState>();
}

void Application::execute() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			m_stateMachine.handleEvents(evnt);
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}

		m_window.clear();

		m_stateMachine.update(0.0f); // todo: input actual dt here
		m_stateMachine.render(m_window);

		m_window.display();
	}
}