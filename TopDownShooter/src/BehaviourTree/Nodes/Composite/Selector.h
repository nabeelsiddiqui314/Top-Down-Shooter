#pragma once
#include "../Base/ICompositeNode.h"

class Selector : public ICompositeNode {
public:
	Selector() = default;
	~Selector() = default;
public:
	Status process() override;
};