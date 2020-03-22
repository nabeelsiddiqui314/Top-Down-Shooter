#pragma once
#include "IState.h"
#include <memory>

class StateMachine
{
public:
	StateMachine() = default;
	~StateMachine() = default;
public:
	template <typename T, typename... Args>
	void setState(Args&&... args) {
		m_currentState = std::make_unique<T>(std::forward<Args>(args)...);
		m_currentState->init(this);
	}

	void handleEvents(const sf::Event& evnt);

	void update(float deltaTime);
	void render(sf::RenderWindow& window);
private:
	std::unique_ptr<IState> m_currentState;
};

