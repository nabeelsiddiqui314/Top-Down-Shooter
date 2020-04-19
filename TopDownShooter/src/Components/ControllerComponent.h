#pragma once
#include "IComponent.h"

class DirectionAttribute;

class ControllerComponent : public IComponent {
public:
	ControllerComponent() = default;
	~ControllerComponent() = default;
public:
	void fetchAttributes(std::shared_ptr<AttributeManager> attributes) override;
	
	void update(float) override;
private:
	std::weak_ptr<DirectionAttribute> m_directionAttribute;
};