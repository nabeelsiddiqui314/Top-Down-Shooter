#pragma once
#include <memory>
#include <vector>

class Event;
class IComponent;
class EntityManager;
class TransformComponent;

class Entity : private std::enable_shared_from_this<Entity> {
private:
	typedef std::shared_ptr<IComponent> IComponentPtr;
public:
	Entity(std::weak_ptr<EntityManager> entityManager);
	Entity(std::weak_ptr<EntityManager> entityManager, float x, float y);
	~Entity() = default;
public:
	void dispatchEvent(Event& event);

	void registerComponent(const IComponentPtr component);
	void removeComponent(const IComponentPtr component);

	void update(float deltaTime);
	
	std::weak_ptr<EntityManager> getEntityManager() const;
	std::shared_ptr<TransformComponent> getTransformComponent() const;
	void destroy();
	bool shouldDestroy() const;
private:
	std::vector<IComponentPtr> m_components;
	std::weak_ptr<EntityManager> m_entityManager;
	bool m_shouldDestroy = false;
	std::shared_ptr<TransformComponent> m_transformComponent;
};