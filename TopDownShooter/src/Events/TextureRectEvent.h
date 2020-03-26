#pragma once
#include "Event.h"
#include "IEventHandler.h"
#include <SFML/Graphics/Rect.hpp>

class TextureRectEvent : public Event {
public:
	sf::IntRect rect;
public:
	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};
