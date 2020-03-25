#pragma once
#include <memory>

class Transform;

class ITransformBehaviour {
public:
	ITransformBehaviour() = default;
	virtual ~ITransformBehaviour() {}
public:
	void setTransformComponent(std::weak_ptr<Transform> transformComponent);
	virtual void update(float deltaTime) = 0;
protected:
	void move(float x, float y);
private:
	std::weak_ptr<Transform> m_transform;
};