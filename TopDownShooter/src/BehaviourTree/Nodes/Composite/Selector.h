#pragma once
#include "../Base/CompositeNode.h"

class Selector : public CompositeNode {
public:
	Selector() = default;
	~Selector() = default;
public:
	Status process() override;
};