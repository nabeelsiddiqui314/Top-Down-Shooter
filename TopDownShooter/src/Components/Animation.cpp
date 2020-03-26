#include "Animation.h"
#include "../Events/TextureRectEvent.h"

Animation::Animation(std::weak_ptr<Entity> parent, const Animator::AnimationInfo& animInfo)
	: IComponent(parent),
	m_animator(animInfo)  {
	TextureRectEvent textureRectEvent;
	textureRectEvent.rect = m_animator.getFrame(m_data.row, m_data.column);

	dispatchEventToParent(textureRectEvent);
}

void Animation::update(float deltaTime) {
	TextureRectEvent textureRectEvent;

	if (m_data.shouldAnimate) {
		textureRectEvent.rect = m_animator.animate(m_data.column, m_data.interval);
	}
	else {
		textureRectEvent.rect = m_animator.getFrame(m_data.row, m_data.column);
	}

	dispatchEventToParent(textureRectEvent);
}

void Animation::handleEvent(const AnimationEvent& event) {
	m_data = event.data;
}