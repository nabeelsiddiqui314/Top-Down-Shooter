#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(std::weak_ptr<Entity> parent, const Animator::AnimationInfo& animInfo)
	: IComponent(parent),
	m_animator(animInfo)  {
	m_currentFrame = m_animator.getFrame(m_row, m_column);
}

void AnimationComponent::update(float deltaTime) {
	if (m_shouldAnimate) {
		m_currentFrame = m_animator.animate(m_column, m_interval);
	}
	else {
		m_currentFrame = m_animator.getFrame(m_row, m_column);
	}
}

void AnimationComponent::setAnimationColumn(int column, float interval) {
	m_column = column;
	m_shouldAnimate = true;
	m_interval = interval;
}

void AnimationComponent::setStillFrame(int row, int column) {
	m_currentFrame = m_animator.getFrame(row, column);
	m_shouldAnimate = false;
}

bool AnimationComponent::shouldAnimate() const {
	return m_shouldAnimate;
}

const sf::IntRect& AnimationComponent::getFrame() const {
	return m_currentFrame;
}
