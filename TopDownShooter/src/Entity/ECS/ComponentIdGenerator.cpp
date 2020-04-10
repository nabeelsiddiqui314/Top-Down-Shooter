#include "ComponentIdGenerator.h"

Component_ID ComponentIdGenerator::getNewID() const {
	static Component_ID ID{ 0 };
	return ID++;
}