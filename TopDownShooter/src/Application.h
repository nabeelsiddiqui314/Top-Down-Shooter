#pragma once
#include "States/StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Application
{
public:
	Application(std::uint16_t windowWidth, std::uint16_t windowHeight, const std::string& title);
	~Application() = default;
public:
	void execute();
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	StateMachine m_stateMachine;

	sf::Clock m_deltaTimeclock;
};

