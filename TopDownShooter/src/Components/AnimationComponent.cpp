#include "AnimationComponent.h"
#include "../Events/TextureRectEvent.h"

AnimationComponent::AnimationComponent(std::weak_ptr<Entity> parent, const Animator::AnimationInfo& animInfo)
	: IComponent(parent),
	m_animator(animInfo)  {
	TextureRectEvent textureRectEvent;
	textureRectEvent.rect = m_animator.getFrame(m_data.row, m_data.column);

	dispatchEventToParent(textureRectEvent);
}

void AnimationComponent::update(float deltaTime) {
	TextureRectEvent textureRectEvent;

	if (m_data.shouldAnimate) {
		textureRectEvent.rect = m_animator.animate(m_data.column, m_data.interval);
	}
	else {
		textureRectEvent.rect = m_animator.getFrame(m_data.row, m_data.column);
	}

	dispatchEventToParent(textureRectEvent);
}

void AnimationComponent::handleEvent(const AnimationEvent& event) {
	m_data = event.data;
}