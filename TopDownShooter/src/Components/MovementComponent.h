#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

namespace sf {
	class RenderWindow;
}
class TransformComponent;

class MovementComponent : public IComponent {
public:
	MovementComponent(std::weak_ptr<Entity> parent, const sf::Vector2f& origin, float speed);
	~MovementComponent() = default;
public:
	void init() override;
	void update(float deltaTime) override;

	void handleEvent(const MoveEvent& moveEvent) override;
private:
	const float m_speed;
	const sf::Vector2f m_origin;
	std::weak_ptr<TransformComponent> m_transformComponent;
	sf::Vector2f m_velocity;
};