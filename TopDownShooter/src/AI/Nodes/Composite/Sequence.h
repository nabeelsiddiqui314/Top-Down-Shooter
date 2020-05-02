#pragma once
#include "../Base/CompositeNode.h"

class Sequence : public CompositeNode {
public:
	Sequence() = default;
	~Sequence() = default;
public:
	Status process() override;
};