#include "Render.h"
#include "../Resources/ResourceManager.h"
#include "../Events/PositionEvent.h"
#include <SFML/Graphics/Texture.hpp>

Render::Render(std::weak_ptr<Entity> parent, sf::RenderWindow* window, const std::string& textureName)
 : IComponent(parent),
   m_window(window) {
	auto& resourceManager = ResourceManager::getInstance();
	m_texture = resourceManager.textureContainer.aquire(textureName);
	m_sprite.setPosition(0,0);
	m_sprite.setTexture(*m_texture);
}

void Render::update(float deltaTime) {
	m_window->draw(m_sprite);
}

void Render::handleEvent(const PositionEvent& event) {
	m_sprite.setPosition(event.position);
}