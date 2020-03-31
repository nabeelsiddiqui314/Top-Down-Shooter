#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class ControllerComponent : public IComponent{
public:
	ControllerComponent(std::weak_ptr<Entity> parent, float speed);
	~ControllerComponent() = default;
public:
	void update(float deltaTime) override;
	void handleEvent(const TransformEvent& event) override;
private:
	sf::Vector2f m_position;
	float m_speed;
	bool m_wasPressed = false;
};