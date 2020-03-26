#pragma once

class Event;
class PositionEvent;
class AnimationEvent;
class TextureRectEvent;

class IEventHandler {
public:
	IEventHandler() {}
	virtual ~IEventHandler() {}
public:
	virtual void handleEvent(const Event&) {};
	virtual void handleEvent(const PositionEvent&) {};
	virtual void handleEvent(const AnimationEvent&) {};
	virtual void handleEvent(const TextureRectEvent&) {};
};