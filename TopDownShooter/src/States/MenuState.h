#pragma once
#include "IState.h"

class MenuState : public IState
{
public:
	MenuState();
	~MenuState();
public:
	void init(StateMachine* stateMachine) override;

	void handleEvents(StateMachine* stateMachine, const sf::Event& evnt) override;

	void update(StateMachine* stateMachine, float deltaTime) override;
	void render(sf::RenderWindow& window) override;
};


