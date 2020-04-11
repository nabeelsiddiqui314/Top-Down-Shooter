#pragma once
#include <memory>
#include "../Events/IEventHandler.h"
#include "../Entity/Entity.h"

class IBlueprint;

class IComponent : public IEventHandler {
public:
	IComponent(std::weak_ptr<Entity> parent);
	virtual ~IComponent() {}
public:
	virtual void init() {};
	virtual void update(float deltaTime) = 0;
	void dispatchEventToParent(Event& event);
protected:
	void destroyParent();
	void addEntityFromBlueprint(std::unique_ptr<IBlueprint>& bluePrint);

	template <typename T, typename... Args>
	void addComponent(Args&&... args) {
		auto parent = m_parent.lock();
		if (parent) {
			parent->addComponent<T>(std::forward<Args>(args)...);
		}
	}

	template <typename T>
	bool hasComponent() {
		auto parent = m_parent.lock();
		if (parent) {
			return parent->hasComponent<T>();
		}
		return false;
	}

	template <typename T>
	std::weak_ptr<T> getComponent() {
		auto parent = m_parent.lock();
		return parent->getComponent<T>();
	}
private:
	std::weak_ptr<Entity> m_parent;
};