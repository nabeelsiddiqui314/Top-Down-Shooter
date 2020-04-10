#pragma once
#include "EcsTypes.h"

class ComponentIdGenerator {
public:
	ComponentIdGenerator() = delete;
	~ComponentIdGenerator() = default;
public:
	template <typename T>
	static Component_ID getUniqueID() {
		static Component_ID ID{ getNewID() };
		return ID;
	}
private:
	Component_ID getNewID() const;
};
