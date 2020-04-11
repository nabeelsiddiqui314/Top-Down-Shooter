#include "Event.h"
#include "IEventHandler.h"

void Event::dispatch(IEventHandler& handler) {
	handler.handleEvent(*this);
}