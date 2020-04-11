#pragma once
#include "Event.h"
#include "IEventHandler.h"
#include <bitset>

class MoveEvent : public Event {
public:
	enum MoveDirection {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	std::bitset<5> directions;
	sf::Vector2f lookingAt;

	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};