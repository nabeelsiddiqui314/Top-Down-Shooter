#pragma once
#include "IComponent.h"
#include "../Utilities/Animator.h"

class AnimationComponent : public IComponent {
public:
	AnimationComponent(std::weak_ptr<Entity> parent, const Animator::AnimationInfo& animInfo);
	~AnimationComponent() = default;
public:
	void update(float deltaTime) override;

	void setAnimationColumn(int column);
	void setStillFrame(int row, int column);

	bool shouldAnimate() const;

	const sf::IntRect& getFrame() const;
private:
	Animator m_animator;
	sf::IntRect m_currentFrame;
	bool m_shouldAnimate = false;
	int m_row = 0;
	int m_column = 0;
	float m_interval = 0.1f;
};