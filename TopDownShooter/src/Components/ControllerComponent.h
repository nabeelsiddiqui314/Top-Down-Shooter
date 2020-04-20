#pragma once
#include <memory>
#include "IComponent.h"

class IController;

class ControllerComponent : public IComponent {
public:
	ControllerComponent(std::unique_ptr<IController>& controller);
	~ControllerComponent() = default;
public:
	void update(float) override;
private:
	std::unique_ptr<IController>& m_controller;
};