#include "RenderComponent.h"
#include "../Utilities/ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include "../Components/TransformComponent.h"
#include "../Components/AnimationComponent.h"

RenderComponent::RenderComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, const std::string& textureName)
 : IComponent(parent),
   m_window(window) {
	auto& resourceManager = ResourceManager::getInstance();
	m_texture = resourceManager.textureContainer.aquire(textureName);
	m_sprite.setPosition(0,0);
	m_sprite.setTexture(*m_texture);
}

void RenderComponent::init() {
	if (hasComponent<TransformComponent>()) {
		m_transformComponent = getComponent<TransformComponent>();
	}
	if (hasComponent<AnimationComponent>()) {
		m_animationComponent = getComponent<AnimationComponent>();
	}
}

void RenderComponent::update(float deltaTime) {
	auto animationComponent = m_animationComponent.lock();
	if (animationComponent) {
		m_sprite.setTextureRect(animationComponent->getFrame());
	}

	auto transformComponent = m_transformComponent.lock();
	if (transformComponent) {
		m_sprite.setOrigin(transformComponent->getOrigin());
		m_sprite.setPosition(transformComponent->getPosition());
		m_sprite.setRotation(transformComponent->getRotation());
		m_window->draw(m_sprite);
	}
}