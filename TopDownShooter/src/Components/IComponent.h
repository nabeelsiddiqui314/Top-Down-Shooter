#pragma once
#include <memory>
#include "../Events/IEventHandler.h"

class Entity;
class IBlueprint;
class TransformComponent;

class IComponent : public IEventHandler {
public:
	IComponent(std::weak_ptr<Entity> parent);
	virtual ~IComponent() {}
public:
	virtual void update(float deltaTime) = 0;
	void dispatchEventToParent(Event& event);
protected:
	void destroyParent();
	void addEntityFromBlueprint(std::unique_ptr<IBlueprint>& bluePrint);
	std::shared_ptr<TransformComponent> getTransformComponent() const;
private:
	std::weak_ptr<Entity> m_parent;
};