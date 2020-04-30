#pragma once
#include <memory>
#include <string>

class SpriteSortRenderer;
class Entity;
class Camera;

class EntityFactory {
public:
	EntityFactory(std::shared_ptr<SpriteSortRenderer> renderer, std::shared_ptr<Camera> camera);
	~EntityFactory() = default;
public:
	std::shared_ptr<Entity> createPlayer() const;
	std::shared_ptr<Entity> createStaticObject(const std::string& name, float x, float y) const;
private:
	std::shared_ptr<SpriteSortRenderer> m_renderer;
	std::shared_ptr<Camera> m_camera;
};