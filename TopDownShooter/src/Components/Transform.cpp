#include "Transform.h"
#include "../Events/PositionEvent.h"
#include "../TransformBehaviours/ITransformBehaviour.h"

Transform::Transform(std::weak_ptr<Entity> parent, std::shared_ptr<ITransformBehaviour> behaviour)
 : IComponent(parent),
   m_transformBehaviour(behaviour) {}

void Transform::update(float deltaTime) {
	m_transformBehaviour->update(deltaTime);
}

void Transform::move(float x, float y) {
	m_position.x += x;
	m_position.y += y;

	PositionEvent posEvent;
	posEvent.position = m_position;

	dispatchEventToParent(posEvent);
}