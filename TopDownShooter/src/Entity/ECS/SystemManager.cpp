#include "SystemManager.h"
#include "ISystem.h"
#include "Entity.h"

SystemManager::ComponentSystem::ComponentSystem(std::shared_ptr<ISystem> system_, const ComponentList& components_)
	: system(system_),
      components(components_) {}

void SystemManager::update(float deltaTime) {
	for (auto& componentSystem : m_systems) {
		componentSystem.system->update(deltaTime);
	}
}

void SystemManager::addSystem(std::shared_ptr<ISystem>&& system, const ComponentList& components) {
	m_systems.emplace_back(system, components);
}

void SystemManager::notifyComponentChange(const Entity& entity, const ComponentList& components) {
	for (auto& componentSystem : m_systems) {
		if ((components & componentSystem.components) == componentSystem.components) {
			componentSystem.system->addEntity(entity);
		}
		else {
			componentSystem.system->removeEntity(entity);
		}
	}
}

void SystemManager::notifyEntityRemoval(const Entity& entity) {
	for (auto& componentSystem : m_systems) {
		componentSystem.system->removeEntity(entity);
	}
}