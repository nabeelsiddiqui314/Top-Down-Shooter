#pragma once

class Event;

class IEventHandler {
public:
	virtual void handleEvent(const Event&) {};
};