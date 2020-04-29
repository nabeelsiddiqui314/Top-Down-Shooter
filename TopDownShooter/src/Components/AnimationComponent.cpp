#include "AnimationComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/AnimationAttribute.h"
#include "../Attributes/SpriteAttribute.h"

AnimationComponent::AnimationComponent(const Animator::AnimationInfo& info)
	: m_animator(info) {}

void AnimationComponent::initAttributes(std::shared_ptr<AttributeManager> attributes) {
	m_animationAttribute = attributes->addAttribue<AnimationAttribute>();
}

void AnimationComponent::fetchAttributes(std::shared_ptr<AttributeManager> attributes) {
	if (attributes->hasAttribute<SpriteAttribute>()) {
		m_spriteAttribute = attributes->getAttribute<SpriteAttribute>();
	}
}

void AnimationComponent::update(float) {
	if (m_spriteAttribute) {
		sf::IntRect frame;

		if (m_animationAttribute->isAnimating) {
			frame = m_animator.animate(m_animationAttribute->column, m_animationAttribute->interval);
		}
		else {
			frame = m_animator.getFrame(m_animationAttribute->row, m_animationAttribute->column);
		}

		m_spriteAttribute->sprite->setTextureRect(frame);
	}
}
