#include "ITransformBehaviour.h"
#include "../Components/Transform.h"

void ITransformBehaviour::setTransformComponent(std::weak_ptr<Transform> transformComponent) {
	m_transform = transformComponent;
}

void ITransformBehaviour::move(float x, float y) {
	auto transform = m_transform.lock();
	if (transform) {
		transform->move(x, y);
	}
}