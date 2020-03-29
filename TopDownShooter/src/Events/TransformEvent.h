#pragma once
#include "Event.h"
#include "IEventHandler.h"
#include <SFML/System/Vector2.hpp>

class TransformEvent : public Event {
public:
	enum class Type {
		CHANGE, 
		TRANSFORM
	};

	Type type;
	sf::Vector2f transformVector;
public:
	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};