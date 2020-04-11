#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent;
namespace sf {
	class RenderWindow;
}

class ControllerComponent : public IComponent{
public:
	ControllerComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window);
	~ControllerComponent() = default;
public:
	void update(float deltaTime) override;
private:
	const std::shared_ptr<sf::RenderWindow> m_window;
	bool m_wasPressed = false;
};