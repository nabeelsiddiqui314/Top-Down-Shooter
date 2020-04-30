#include "Camera.h"
#include <SFML/Graphics/RenderWindow.hpp>

void Camera::setCentre(const sf::Vector2f& position) {
	m_view.setCenter(position);
}

void Camera::updateView(sf::RenderWindow& window) {
	m_view.setSize(static_cast<float>(window.getSize().x),
		           static_cast<float>(window.getSize().y));
	window.setView(m_view);
}
