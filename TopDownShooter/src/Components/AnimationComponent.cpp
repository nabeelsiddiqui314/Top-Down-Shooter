#include "AnimationComponent.h"
#include "../Attributes/AttributeManager.h"
#include "../Attributes/AnimationAttribute.h"
#include "../Attributes/SpriteAttribute.h"

AnimationComponent::AnimationComponent(std::weak_ptr<AttributeManager> attributes, const Animator::AnimationInfo& info)
	: IComponent(attributes), m_animator(info) {}

void AnimationComponent::init() {
	auto attributes = m_attributes.lock();
	if (attributes->hasAttribute<AnimationAttribute>()) {
		m_animationAttribute = attributes->getAttribute<AnimationAttribute>();
	}
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
			frame = m_animator.animate(animationAttrib->row, animationAttrib->interval);
		}
		else {
			frame = m_animator.getFrame(animationAttrib->row, animationAttrib->column);
		}

		spriteAttrib->sprite.setTextureRect(frame);
	}
}
