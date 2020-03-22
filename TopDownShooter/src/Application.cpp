#include "Application.h"
#include <SFML/Window/Event.hpp>

Application::Application(std::uint16_t windowWidth, std::uint16_t windowHeight, const std::string& title) {
	m_window.create(sf::VideoMode(windowWidth, windowHeight), title);
}

void Application::execute() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}

			m_window.clear();
			m_window.display();
		}
	}
}