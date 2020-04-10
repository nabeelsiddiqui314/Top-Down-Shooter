#pragma once
#include <cstdint>
#include <bitset>
#include "../../Events/EventChannel.h"

using Entity_ID = std::uint32_t;
using Component_ID = std::uint8_t;

constexpr int COMPONENTS_LIMIT = 256;
using ComponentBitset = std::bitset<COMPONENTS_LIMIT>;

struct EntityAddEvent {
	
};

struct EntityDestroyedEvent {
	Entity_ID entity;
};

using ECS_Events = EventChannel<EntityAddEvent, EntityDestroyedEvent>;