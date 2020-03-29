#pragma once
#include "IComponent.h"
#include "../Utilities/Animator.h"
#include "../Events/AnimationEvent.h"

class AnimationComponent : public IComponent {
public:
	AnimationComponent(std::weak_ptr<Entity> parent, const Animator::AnimationInfo& animInfo);
	~AnimationComponent() = default;
public:
	void update(float deltaTime) override;
	void handleEvent(const AnimationEvent& event) override;
private:
	Animator m_animator;
	AnimationData m_data;
};