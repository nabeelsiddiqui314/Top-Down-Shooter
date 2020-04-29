#include "RenderComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/TransformAttribute.h"
#include "../Attributes/SpriteAttribute.h"
#include "../Utilities/ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include "../Utilities/SpriteSortRenderer.h"

RenderComponent::RenderComponent(const std::string& texturePath, std::shared_ptr<SpriteSortRenderer> renderer)
	: m_renderer(renderer) {
	auto& resourceManager = ResourceManager::getInstance();
	m_texture = resourceManager.textureContainer.aquire(texturePath);
}

RenderComponent::~RenderComponent() {
	m_renderer->removeSprite(m_sprite->sprite);
}

void RenderComponent::initAttributes(std::shared_ptr<AttributeManager> attributes) {
	m_sprite = attributes->addAttribue<SpriteAttribute>();

	m_sprite->sprite = std::make_shared<sf::Sprite>();
	m_sprite->sprite->setTexture(*m_texture);

	m_renderer->addSprite(m_sprite->sprite);
}

void RenderComponent::fetchAttributes(std::shared_ptr<AttributeManager> attributes) {
	if (attributes->hasAttribute<TransformAttribute>()) {
		m_transform = attributes->getAttribute<TransformAttribute>();
	}	
}

void RenderComponent::update(float) {
	if (m_transform) {
		m_sprite->sprite->setPosition(m_transform->position);
		m_sprite->sprite->setScale(m_transform->scale);
	}
}