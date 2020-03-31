#include "BulletBlueprint.h"
#include "../../Components/TransformComponent.h"
#include "../../Components/ProjectileComponent.h"
#include "../../Components/RenderComponent.h"
#include "../../Components/TimedLifetimeComponent.h"
#include "../Entity.h"

BulletBlueprint::BulletBlueprint(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, 
	const sf::Vector2f& pos, const sf::Vector2f& velocity, const std::string& textureName)
  : m_parent(parent),
	m_window(window),
	m_pos(pos),
	m_velocity(velocity),
	m_textureName(textureName) {
}

std::shared_ptr<Entity> BulletBlueprint::getEntity() {
	auto bullet = std::make_shared<Entity>(m_parent.lock()->getEntityManager());

	auto transformComponent = std::make_shared<TransformComponent>(bullet, m_pos.x, m_pos.y);
	auto projectileComponent = std::make_shared<ProjectileComponent>(bullet, m_velocity.x, m_velocity.y);
	auto renderComponent = std::make_shared<RenderComponent>(bullet, m_window, m_textureName);
	auto timedLifetimeComponent = std::make_shared<TimedLifetimeComponent>(bullet, 7);

	bullet->registerComponent(transformComponent);
	bullet->registerComponent(projectileComponent);
	bullet->registerComponent(renderComponent);
	bullet->registerComponent(timedLifetimeComponent);

	return bullet;
}