#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent;
namespace sf {
	class RenderWindow;
}

class ControllerComponent : public IComponent{
public:
	ControllerComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, float speed);
	~ControllerComponent() = default;
public:
	void init() override;
	void update(float deltaTime) override;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	float m_speed;
	bool m_wasPressed = false;
	std::weak_ptr<TransformComponent> m_transformComponent;
};