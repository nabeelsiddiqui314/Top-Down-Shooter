#pragma once
#include <memory>
#include <vector>
#include "EcsTypes.h"

class ISystem;
class Entity;

class SystemManager {
private:
	struct ComponentSystem {
		ComponentSystem(std::shared_ptr<ISystem> system_, const ComponentList& components_);

		std::shared_ptr<ISystem> system;
		ComponentList components;
	};
public:
	SystemManager() = default;
	~SystemManager() = default;
public:
	void update(float deltaTime);
	void addSystem(std::shared_ptr<ISystem>&& system, const ComponentList& components);

	void notifyComponentChange(const Entity& entity, const ComponentList& components);
	void notifyEntityRemoval(const Entity& entity);
private:
	std::vector<ComponentSystem> m_systems;
};