#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Application
{
public:
	Application(std::uint16_t windowWidth, std::uint16_t windowHeight, const std::string& title);
	~Application() = default;
public:
	void execute();
private:
	sf::RenderWindow m_window;
};

