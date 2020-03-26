#pragma once
#include "IComponent.h"
#include "../Utilities/Animator.h"
#include "../Events/AnimationEvent.h"

class Animation : public IComponent {
public:
	Animation(std::weak_ptr<Entity> parent, const Animator::AnimationInfo& animInfo);
	~Animation() = default;
public:
	void update(float deltaTime) override;
	void handleEvent(const AnimationEvent& event) override;
private:
	Animator m_animator;
	AnimationData m_data;
};