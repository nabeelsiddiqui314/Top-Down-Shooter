#pragma once
#include "Event.h"
#include "IEventHandler.h"
#include <SFML/System/Vector2.hpp>

class PositionEvent : public Event {
public:
	sf::Vector2f position;
public:
	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};