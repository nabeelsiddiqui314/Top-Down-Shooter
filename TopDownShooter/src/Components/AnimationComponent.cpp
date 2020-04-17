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
	auto animationAttrib = m_animationAttribute.lock();
	auto spriteAttrib = m_spriteAttribute.lock();
	if (animationAttrib && spriteAttrib) {
		sf::IntRect frame;

		if (animationAttrib->isAnimating) {
			frame = m_animator.animate(animationAttrib->column, animationAttrib->interval);
		}
		else {
			frame = m_animator.getFrame(animationAttrib->row, animationAttrib->column);
		}

		spriteAttrib->sprite.setTextureRect(frame);
	}
}
