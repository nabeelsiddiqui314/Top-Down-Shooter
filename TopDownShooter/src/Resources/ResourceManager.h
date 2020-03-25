#pragma once
#include "ResourceContainer.h"

namespace sf {
	class Texture;
	class Font;
	class SoundBuffer;
}

class ResourceManager {
private:
	ResourceManager();
public:
	ResourceManager(ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(ResourceManager&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;
public:
	static ResourceManager& getInstance();
public:
	ResourceContainer<sf::Texture> textureContainer;
	ResourceContainer<sf::Font> fontContainer;
	ResourceContainer<sf::SoundBuffer> soundBufferContainer;
};