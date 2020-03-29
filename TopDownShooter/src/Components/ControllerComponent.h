#pragma once
#include "IComponent.h"

class ControllerComponent : public IComponent{
public:
	ControllerComponent(std::weak_ptr<Entity> parent, float speed);
	~ControllerComponent() = default;
public:
	void update(float deltaTime) override;
private:
	float m_speed;
};