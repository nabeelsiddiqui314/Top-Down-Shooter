#pragma once
#include <memory>
#include "ICommand.h"
#include "../Attributes/DirectionAttribute.h"

class MovementComponent;

class MoveCommand : public ICommand {
public:
	MoveCommand(std::shared_ptr<MovementComponent> movementComponent, const Direction& direction);
	~MoveCommand() = default;
public:
	void execute() override;
private:
	std::shared_ptr<MovementComponent> m_movementComponent;
	Direction m_direction;
};