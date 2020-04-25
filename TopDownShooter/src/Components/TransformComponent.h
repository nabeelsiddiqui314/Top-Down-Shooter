#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class TransformAttribute;
class VelocityAttribute;

class TransformComponent : public IComponent {
public:
	TransformComponent(float x, float y);
	TransformComponent(float x, float y, float scaleX, float scaleY);
	~TransformComponent() = default;
public:
	void initAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void fetchAttributes(std::shared_ptr<AttributeManager> attributes) override;

	void update(float deltaTime) override;
private:
	sf::Vector2f m_originalPosition;
	sf::Vector2f m_scale;
	std::weak_ptr<TransformAttribute> m_transformAttribute;
	std::weak_ptr<VelocityAttribute> m_velocityAttribute;
};