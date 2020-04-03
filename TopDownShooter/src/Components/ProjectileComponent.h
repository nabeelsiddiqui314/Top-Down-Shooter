#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent;

class ProjectileComponent : public IComponent {
public:
	ProjectileComponent(std::weak_ptr<Entity> parent, float velocity, float rotation);
	~ProjectileComponent() = default;
public:
	void init() override;
	void update(float deltaTime) override;
private:
	const float m_velocity;
	const float m_rotation;
	std::weak_ptr<TransformComponent> m_transformComponent;
};