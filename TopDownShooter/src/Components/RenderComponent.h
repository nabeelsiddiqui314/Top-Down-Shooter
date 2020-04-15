#pragma once
#include "IComponent.h"
#include <string>

namespace sf {
	class RenderWindow;
	class Texture;
}

class TransformAttribute;
class SpriteAttribute;

class RenderComponent : public IComponent {
public:
	RenderComponent(std::weak_ptr<AttributeManager> attributes, const std::string& texturePath,
		std::shared_ptr<sf::RenderWindow> window);
	~RenderComponent() = default;
public:
	void init() override;
	void update(float) override;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<sf::Texture> m_texture;
	std::weak_ptr<TransformAttribute> m_transform;
	std::weak_ptr<SpriteAttribute> m_sprite;
};