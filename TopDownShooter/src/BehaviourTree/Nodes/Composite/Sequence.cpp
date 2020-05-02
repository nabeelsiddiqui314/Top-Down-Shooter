#include "Sequence.h"

Status Sequence::process() {
	for (auto& child : getChildrenNodes()) {
		Status status = child->process();

		if (status != Status::SUCCESS) {
			return status;
		}
	}

	return Status::SUCCESS;
}
