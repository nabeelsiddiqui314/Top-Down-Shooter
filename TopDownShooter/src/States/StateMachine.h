#pragma once
#include "IState.h"
#include <memory>

class StateMachine
{
public:
	StateMachine(std::shared_ptr<sf::RenderWindow> window);
	~StateMachine() = default;
public:
	template <typename T, typename... Args>
	void setState(Args&&... args) {
		m_currentState = std::make_unique<T>(std::forward<Args>(args)...);
		m_currentState->init(this);
	}

	void handleEvents(const sf::Event& evnt);

	void update(float deltaTime);
	void render();

	std::shared_ptr<sf::RenderWindow> getWindow() const;
private:
	std::unique_ptr<IState> m_currentState;
	std::shared_ptr<sf::RenderWindow> m_window;
};

