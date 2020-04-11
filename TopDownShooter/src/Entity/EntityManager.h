#pragma once
#include <memory>
#include <vector>
#include "../Subsystems/ISubSystem.h"

class Entity;

class EntityManager {
private:
	typedef std::shared_ptr<Entity> EntityPtr;
	typedef std::unique_ptr<ISubSystem> ISubSystemPtr;
public:
	EntityManager() = default;
	~EntityManager() = default;
public:
	void addEntity(std::shared_ptr<Entity> entity);

	template <typename T, typename... Args>
	void addSubSystem(Args&&... args) {
		m_subSystems.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
	}
	
	void update(float deltaTime);
private:
	std::vector<EntityPtr> m_entities;
	std::vector<ISubSystemPtr> m_subSystems;
};