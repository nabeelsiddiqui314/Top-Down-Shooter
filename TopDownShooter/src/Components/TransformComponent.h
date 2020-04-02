#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent : public IComponent {
public:
	TransformComponent(std::weak_ptr<Entity> parent);
	TransformComponent(std::weak_ptr<Entity> parent, float x, float y);
	~TransformComponent() = default;
public:
	void update(float deltaTime) override;
	
	void setVelocity(float x, float y);
	const sf::Vector2f& getPosition() const;

	void setOrigin(float x, float y);
	const sf::Vector2f& getOrigin() const;

	void setRotation(float angle);
	float getRotation() const;
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_origin;
	float m_rotation = 0;
};