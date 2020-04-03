#pragma once

class Event;
class GunFireEvent;
class MoveEvent;

class IEventHandler {
public:
	IEventHandler() {}
	virtual ~IEventHandler() {}
public:
	virtual void handleEvent(const Event&) {};
	virtual void handleEvent(const GunFireEvent&) {};
	virtual void handleEvent(const MoveEvent&) {};
};