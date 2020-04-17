#pragma once
#include "IComponent.h"
#include "../Utilities/Animator.h"

class AnimationAttribute;
class SpriteAttribute;

class AnimationComponent : public IComponent {
public:
	AnimationComponent(const Animator::AnimationInfo& info);
	~AnimationComponent() = default;
public:
	void initAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void fetchAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void update(float) override;
private:
	Animator m_animator;
	std::weak_ptr<AnimationAttribute> m_animationAttribute;
	std::weak_ptr<SpriteAttribute> m_spriteAttribute;
};