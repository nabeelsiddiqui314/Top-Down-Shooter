#pragma once
#include "IComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Render : public IComponent {
public:
	Render(std::weak_ptr<Entity> parent, sf::RenderWindow* window, const std::string& textureName);
	~Render() = default;
public:
	void update(float deltaTime) override;

	void handleEvent(const PositionEvent& event) override;
private:
	sf::RenderWindow* m_window;
	sf::Sprite m_sprite;
	std::shared_ptr<sf::Texture> m_texture;
};