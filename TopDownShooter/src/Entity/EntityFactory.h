#pragma once
#include <memory>

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
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::weak_ptr<EntityManager> m_entityManager;
};