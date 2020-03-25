#pragma once
#include <memory>

class Transform;

class ITransformBehaviour {
public:
	ITransformBehaviour(std::weak_ptr<Transform> transformComponent)
		: p_transform(transformComponent) {}
	virtual ~ITransformBehaviour() {}
public:
	virtual void update(float deltaTime) = 0;
protected:
	std::weak_ptr<Transform> p_transform;
};