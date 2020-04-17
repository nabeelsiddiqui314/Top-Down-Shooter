#pragma once
#include <memory>

class AttributeManager;

class IComponent {
public:
	IComponent() = default;
	virtual ~IComponent() {}
public:
	virtual void initAttributes(std::shared_ptr<AttributeManager> attributes) {};
	virtual void fetchAttributes(std::shared_ptr<AttributeManager> attribute) {}

	virtual void update(float deltaTime) = 0;
};