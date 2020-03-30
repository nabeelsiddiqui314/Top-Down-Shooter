#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class ProjectileComponent : public IComponent {
public:
	ProjectileComponent(std::weak_ptr<Entity> parent, float velocityX, float velocityY);
	~ProjectileComponent() = default;
public:
	void update(float deltaTime) override;
private:
	const sf::Vector2f m_velocity;
};