#include "RenderComponent.h"
#include "../Utilities/ResourceManager.h"
#include "../Events/TransformEvent.h"
#include <SFML/Graphics/Texture.hpp>
#include "../Events/TextureRectEvent.h"

RenderComponent::RenderComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, const std::string& textureName)
 : IComponent(parent),
   m_window(window) {
	auto& resourceManager = ResourceManager::getInstance();
	m_texture = resourceManager.textureContainer.aquire(textureName);
	m_sprite.setPosition(0,0);
	m_sprite.setTexture(*m_texture);
}

void RenderComponent::update(float deltaTime) {
	m_window->draw(m_sprite);
}

void RenderComponent::handleEvent(const TransformEvent& event) {
	if (event.type == TransformEvent::Type::TRANSFORM) {
		m_sprite.setPosition(event.transformVector);
	}
}

void RenderComponent::handleEvent(const TextureRectEvent& event) {
	m_sprite.setTextureRect(event.rect);
}