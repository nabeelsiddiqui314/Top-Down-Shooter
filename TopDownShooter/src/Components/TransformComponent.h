#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent : public IComponent {
public:
	TransformComponent(std::weak_ptr<Entity> parent);
	~TransformComponent() = default;
public:
	void update(float deltaTime) override;

	void handleEvent(const TransformEvent& event) override;
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};