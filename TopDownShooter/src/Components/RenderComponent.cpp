#include "RenderComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/TransformAttribute.h"
#include "../Attributes/SpriteAttribute.h"
#include "../Utilities/ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

RenderComponent::RenderComponent(std::weak_ptr<AttributeManager> attributes, const std::string& texturePath,
	std::shared_ptr<sf::RenderWindow> window) 
	: IComponent(attributes), m_window(window) {
	auto& resourceManager = ResourceManager::getInstance();
	m_texture = resourceManager.textureContainer.aquire(texturePath);
}

void RenderComponent::init() {
	auto attributes = m_attributes.lock();
	if (attributes->hasAttribute<TransformAttribute>()) {
		m_transform = attributes->getAttribute<TransformAttribute>();
	}
	if (attributes->hasAttribute<SpriteAttribute>()) {
		m_sprite = attributes->getAttribute<SpriteAttribute>();
		m_sprite.lock()->sprite.setTexture(*m_texture);
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