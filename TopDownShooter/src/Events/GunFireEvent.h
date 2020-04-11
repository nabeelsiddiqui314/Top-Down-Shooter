#pragma once
#include "Event.h"
#include "IEventHandler.h"
#include <SFML/System/Vector2.hpp>
#include <string>

class GunFireEvent : public Event {
public:
	float velocity;
	std::string bulletName;

	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};