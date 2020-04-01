#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformComponent;
class AnimationComponent;

class ControllerComponent : public IComponent{
public:
	ControllerComponent(std::weak_ptr<Entity> parent, float speed);
	~ControllerComponent() = default;
public:
	void init() override;
	void update(float deltaTime) override;
private:
	float m_speed;
	bool m_wasPressed = false;
	std::weak_ptr<TransformComponent> m_transformComponent;
	std::weak_ptr<AnimationComponent> m_animationComponent;
};