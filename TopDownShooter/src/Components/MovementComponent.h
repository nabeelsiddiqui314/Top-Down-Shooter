#pragma once
#include "IComponent.h"

class VelocityAttribute;
class DirectionAttribute;

class MovementComponent : public IComponent {
public:
	MovementComponent(float speed);
	~MovementComponent() = default;
public:
	void initAttributes(std::shared_ptr<AttributeManager> attributes) override;

	void update(float) override;
private:
	const float m_speed;
	std::weak_ptr<VelocityAttribute> m_velocityAttribute;
	std::weak_ptr<DirectionAttribute> m_directionAttribute;
};