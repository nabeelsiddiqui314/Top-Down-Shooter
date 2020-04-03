#include "BulletBlueprint.h"
#include "../../Components/TransformComponent.h"
#include "../../Components/ProjectileComponent.h"
#include "../../Components/RenderComponent.h"
#include "../../Components/TimedLifetimeComponent.h"
#include "../Entity.h"
#include "../../Utilities/ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>

BulletBlueprint::BulletBlueprint(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, 
	const sf::Vector2f& pos, const float rotation, const float velocity, const std::string& textureName)
  : m_parent(parent),
	m_window(window),
	m_pos(pos),
	m_rotation(rotation),
	m_velocity(velocity),
	m_textureName(textureName) {
}

std::shared_ptr<Entity> BulletBlueprint::getEntity() {
	auto bullet = std::make_shared<Entity>(m_parent.lock()->getEntityManager());

	bullet->addComponent<TransformComponent>(bullet, m_pos.x, m_pos.y);
	bullet->addComponent<ProjectileComponent>(bullet, m_velocity, m_rotation);
	bullet->addComponent<RenderComponent>(bullet, m_window, m_textureName);
	bullet->addComponent<TimedLifetimeComponent>(bullet, 7);

	auto transform = bullet->getComponent<TransformComponent>().lock();
	auto texture = ResourceManager::getInstance().textureContainer.aquire(m_textureName);
	transform->setOrigin(0, texture->getSize().y / 2);
	transform->setRotation(m_rotation);
	return bullet;
}