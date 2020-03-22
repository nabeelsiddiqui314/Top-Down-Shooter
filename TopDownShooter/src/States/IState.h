#pragma once

class StateMachine;

namespace sf {
	class RenderWindow;
	class Event;
}

class IState
{
public:
	IState() {}
	virtual ~IState() {}
public:
	virtual void init(StateMachine* stateMachine) {}

	virtual void handleEvents(StateMachine* stateMachine, const sf::Event& evnt) {}
	virtual void update(StateMachine* stateMachine, float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
};

