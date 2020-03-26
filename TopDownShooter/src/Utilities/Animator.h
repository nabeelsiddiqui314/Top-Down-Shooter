#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

class Animator {
public:
	struct AnimationInfo {
		int width, height;
		std::vector<int> columns;
	};
public:
	Animator(const AnimationInfo& animInfo);
	~Animator() = default;
public:
	const sf::IntRect getFrame(int row, int column) const;
	const sf::IntRect animate(int column, float interval);
private:
	const AnimationInfo m_animationInfo;
	sf::Clock m_animationClock;
	int m_currentRow = 0;
};