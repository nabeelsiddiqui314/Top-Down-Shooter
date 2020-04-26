#pragma once
#include "IComponent.h"

class VelocityAttribute;
class DirectionAttribute;

enum class Direction : std::uint8_t;

class MovementComponent : public IComponent {
public:
	MovementComponent(float speed);
	~MovementComponent() = default;
public:
	void initAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void update(float) override;

	void setMovementDirection(const Direction& direction);
private:
	const float m_speed;
	std::shared_ptr<VelocityAttribute> m_velocityAttribute;
	std::shared_ptr<DirectionAttribute> m_directionAttribute;
};