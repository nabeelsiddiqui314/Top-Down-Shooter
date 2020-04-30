#pragma once
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

namespace sf {
	class RenderWindow;
}

class Camera {
public:
	Camera() = default;
	~Camera() = default;
public:
	void setCentre(const sf::Vector2f& position);
	void updateView(sf::RenderWindow& window);
private:
	sf::View m_view;
};