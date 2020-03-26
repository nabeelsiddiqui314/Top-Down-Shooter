#include "Animator.h"

Animator::Animator(const AnimationInfo& animInfo) 
	: m_animationInfo(animInfo) {}

const sf::IntRect Animator::getFrame(int row, int column) const {
	return sf::IntRect(m_animationInfo.width * row, m_animationInfo.height * column,
		               m_animationInfo.width      , m_animationInfo.height);
}

const sf::IntRect Animator::animate(int column, float interval) {
	if (m_animationClock.getElapsedTime().asMilliseconds() >= interval) {
		m_currentRow++;
		m_currentRow %= m_animationInfo.columns[column];
		m_animationClock.restart();
	}

	return getFrame(m_currentRow, column);
}
