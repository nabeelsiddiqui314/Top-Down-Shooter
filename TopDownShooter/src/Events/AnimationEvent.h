#pragma once
#include "Event.h"
#include "IEventHandler.h"

struct AnimationData {
	bool shouldAnimate = false;
	int row = 0;
	int column = 0;
	float interval = 0.0f;
};

class AnimationEvent : public Event {
public:
	AnimationData data;
public:
	void dispatch(IEventHandler& handler) override {
		handler.handleEvent(*this);
	}
};