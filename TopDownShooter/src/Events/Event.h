#pragma once

class IEventHandler;

class Event {
public:
	virtual void dispatch(IEventHandler& handler);
};