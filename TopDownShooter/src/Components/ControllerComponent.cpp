#include "ControllerComponent.h"
#include "../Controllers/IController.h"

ControllerComponent::ControllerComponent(std::unique_ptr<IController>& controller) 
	: m_controller(controller) {}

void ControllerComponent::update(float) {
	m_controller->update();
}
