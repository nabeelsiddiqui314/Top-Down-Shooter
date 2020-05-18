#pragma once
#include "../Base/ICompositeNode.h"

class Sequence : public ICompositeNode {
public:
	Sequence() = default;
	~Sequence() = default;
public:
	Status process() override;
};