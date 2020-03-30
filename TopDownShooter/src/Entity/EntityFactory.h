#pragma once
#include <memory>

namespace sf {
	class RenderWindow;
}

class Entity;

class EntityFactory {
public:
	EntityFactory(std::shared_ptr<sf::RenderWindow> window);
	~EntityFactory() = default;
public:
	std::shared_ptr<Entity> createPlayer() const;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
};