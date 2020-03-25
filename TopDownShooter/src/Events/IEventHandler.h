#pragma once

class Event;
class PositionEvent;

class IEventHandler {
public:
	IEventHandler() {}
	virtual ~IEventHandler() {}
public:
	virtual void handleEvent(const Event&) {};
	virtual void handleEvent(const PositionEvent&) {};
};