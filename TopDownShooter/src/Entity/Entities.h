#pragma once
#include <vector>
#include <memory>
#include "EntityFactory.h"


namespace sf {
	class RenderWindow;
}
class SpriteSortRenderer;
class Camera;
class EntityManager;

class Entities {
public:
	Entities();
	~Entities() = default;
public:
	void create();
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
private:
	std::shared_ptr<SpriteSortRenderer> m_spriteRenderer;
	std::shared_ptr<Camera> m_camera;
	std::shared_ptr<EntityManager> m_entityManager;
	EntityFactory m_entityfactory;
};