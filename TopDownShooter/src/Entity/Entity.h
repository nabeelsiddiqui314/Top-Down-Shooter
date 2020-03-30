#pragma once
#include <memory>
#include <vector>

class Event;
class IComponent;

class Entity {
private:
	typedef std::shared_ptr<IComponent> IComponentPtr;
public:
	Entity() = default;
	~Entity() = default;
public:
	void dispatchEvent(Event& event);

	void registerComponent(const IComponentPtr& component);
	void removeComponent(const IComponentPtr& component);

	void update(float deltaTime);
	
	void destroy();
	bool shouldDestroy() const;
private:
	std::vector<IComponentPtr> m_components;
	bool m_shouldDestroy = false;
};