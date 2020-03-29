#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class Transform : public IComponent {
public:
	Transform(std::weak_ptr<Entity> parent);
	~Transform() = default;
public:
	void update(float deltaTime) override;

	void handleEvent(const TransformEvent& event) override;
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};