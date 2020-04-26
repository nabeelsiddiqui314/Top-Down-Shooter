#include "SpriteSortRenderer.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void SpriteSortRenderer::addSprite(SpritePtr sprite) {
	m_sprites.emplace_back(sprite);
}

void SpriteSortRenderer::removeSprite(SpritePtr sprite) {
	m_sprites.erase(std::find(m_sprites.begin(), m_sprites.end(), sprite));
}

void SpriteSortRenderer::renderSprites(sf::RenderWindow& window) {
	sort();
	for (auto& sprite : m_sprites) {
		window.draw(*sprite);
	}
}

void SpriteSortRenderer::sort() {
	for (std::size_t i = 0; i < m_sprites.size() - 1; i++) {
		float firstUnsorted = getPositionAt(i + 1);

		for (std::size_t j = i + 1; j > 0; j--) {
			if (getPositionAt(j - 1) > getPositionAt(j)) {
				std::swap(m_sprites[j], m_sprites[j - 1]);
			}
			else {
				break;
			}
		}
	}
}

float SpriteSortRenderer::getPositionAt(std::size_t index) const {
	auto& sprite = m_sprites[index];
	return sprite->getPosition().y + sprite->getGlobalBounds().height;
}