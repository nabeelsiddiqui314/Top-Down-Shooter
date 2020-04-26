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
	RenderComponent(const std::string& texturePath, std::shared_ptr<sf::RenderWindow> window);
	~RenderComponent() = default;
public:
	void initAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void fetchAttributes(std::shared_ptr<AttributeManager> attributes) override;

	void update(float) override;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<sf::Texture> m_texture;
	std::shared_ptr<TransformAttribute> m_transform;
	std::shared_ptr<SpriteAttribute> m_sprite;
};