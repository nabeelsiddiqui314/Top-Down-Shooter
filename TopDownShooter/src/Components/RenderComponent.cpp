#include "RenderComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/TransformAttribute.h"
#include "../Attributes/SpriteAttribute.h"
#include "../Utilities/ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

RenderComponent::RenderComponent(const std::string& texturePath, std::shared_ptr<sf::RenderWindow> window) 
	: m_window(window) {
	auto& resourceManager = ResourceManager::getInstance();
	m_texture = resourceManager.textureContainer.aquire(texturePath);
}

void RenderComponent::initAttributes(std::shared_ptr<AttributeManager> attributes) {
	attributes->addAttribue<TransformAttribute>();
	m_sprite = attributes->addAttribue<SpriteAttribute>();
	m_sprite.lock()->sprite.setTexture(*m_texture);
}

void RenderComponent::fetchAttributes(std::shared_ptr<AttributeManager> attributes) {
	if (attributes->hasAttribute<TransformAttribute>()) {
		m_transform = attributes->getAttribute<TransformAttribute>();
	}	
}

void RenderComponent::update(float) {
	auto transform = m_transform.lock();
	auto spriteAttrib = m_sprite.lock();

	if (transform && spriteAttrib) {
		spriteAttrib->sprite.setPosition(transform->position);
		m_window->draw(spriteAttrib->sprite);
	}
}