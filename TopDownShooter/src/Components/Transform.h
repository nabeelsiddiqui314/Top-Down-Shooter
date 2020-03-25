#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

class ITransformBehaviour;

class Transform : public IComponent {
public:
	Transform(std::weak_ptr<Entity> parent, std::shared_ptr<ITransformBehaviour> behaviour);
	~Transform() = default;
public:
	void update(float deltaTime) override;
	void move(float x, float y);
private:
	sf::Vector2f m_position;
	std::shared_ptr<ITransformBehaviour> m_transformBehaviour;
};