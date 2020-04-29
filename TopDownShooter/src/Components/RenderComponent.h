#pragma once
#include "IComponent.h"
#include <string>

namespace sf {
	class Texture;
}

class SpriteSortRenderer;
class TransformAttribute;
class SpriteAttribute;

class RenderComponent : public IComponent {
public:
	RenderComponent(const std::string& texturePath, std::shared_ptr<SpriteSortRenderer> renderer);
	~RenderComponent();
public:
	void initAttributes(std::shared_ptr<AttributeManager> attributes) override;
	void fetchAttributes(std::shared_ptr<AttributeManager> attributes) override;

	void update(float) override;
private:
	std::shared_ptr<SpriteSortRenderer> m_renderer;
	std::shared_ptr<sf::Texture> m_texture;
	std::shared_ptr<TransformAttribute> m_transform;
	std::shared_ptr<SpriteAttribute> m_sprite;
};