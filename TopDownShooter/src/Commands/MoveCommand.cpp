#include "MoveCommand.h"
#include "../Components/MovementComponent.h"

MoveCommand::MoveCommand(std::shared_ptr<MovementComponent> movementComponent, const Direction& direction)
	: m_movementComponent(movementComponent), m_direction(direction) {}

void MoveCommand::execute() {
	m_movementComponent->setMovementDirection(m_direction);
}