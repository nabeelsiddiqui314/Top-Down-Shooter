#pragma once
#include "Event.h"
#include "IEventHandler.h"
#include <SFML/System/Vector2.hpp>
#include <string>

class GunFireEvent : public Event {
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	std::string bulletTexture;

	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};