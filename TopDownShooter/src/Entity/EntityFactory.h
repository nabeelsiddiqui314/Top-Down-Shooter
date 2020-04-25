#pragma once
#include <memory>
#include "../Utilities/InputHandler.h"

namespace sf {
	class RenderWindow;
}

class Entity;
class EntityManager;

class EntityFactory {
public:
	EntityFactory(std::shared_ptr<sf::RenderWindow> window, std::weak_ptr<EntityManager> entityManager);
	~EntityFactory() = default;
public:
	std::shared_ptr<Entity> createPlayer() const;
	std::shared_ptr<Entity> createStaticObject(const std::string& name, float x, float y) const;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::weak_ptr<EntityManager> m_entityManager;
	std::shared_ptr<InputHandler> m_playerInputHandler;
};