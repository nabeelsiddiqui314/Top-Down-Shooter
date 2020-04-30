#pragma once
#include "EventChannel.h"

class EntityEventManager {
public:
	EventChannel<> events;
};