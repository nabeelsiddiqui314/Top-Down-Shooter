#include "Selector.h"

Status Selector::process() {
	for (auto& child : getChildrenNodes()) {
		Status status = child->process();
		
		if (status != Status::FALIURE) {
			return status;
		}
	}

	return Status::FALIURE;
}
