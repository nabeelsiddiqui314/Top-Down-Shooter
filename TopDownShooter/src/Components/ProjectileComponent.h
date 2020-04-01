#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent;

class ProjectileComponent : public IComponent {
public:
	ProjectileComponent(std::weak_ptr<Entity> parent, float velocityX, float velocityY);
	~ProjectileComponent() = default;
public:
	void init() override;
	void update(float deltaTime) override;
private:
	const sf::Vector2f m_velocity;
	std::weak_ptr<TransformComponent> m_transformComponent;
};