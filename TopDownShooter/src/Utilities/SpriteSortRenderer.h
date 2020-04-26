#pragma once
#include <memory>
#include <vector>

namespace sf {
	class Sprite;
	class RenderWindow;
}

class SpriteSortRenderer {
private:
	typedef std::shared_ptr<sf::Sprite> SpritePtr;
public:
	SpriteSortRenderer() = default;
	~SpriteSortRenderer() = default;
public:
	void addSprite(SpritePtr sprite);
	void removeSprite(SpritePtr sprite);

	void renderSprites(sf::RenderWindow& window);
private:
	void sort();
	float getPositionAt(std::size_t index) const;
private:
	std::vector<SpritePtr> m_sprites;
};