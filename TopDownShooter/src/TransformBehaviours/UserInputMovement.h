#pragma once
#include "ITransformBehaviour.h"

class UserInputMovement : public ITransformBehaviour {
public:
	UserInputMovement(float speed);
	~UserInputMovement() = default;
public:
	void setTransformComponent(std::weak_ptr<Transform> transform);
	void update(float deltaTime) override;
private:
	std::weak_ptr<Transform> m_transform;
	float m_speed;
};