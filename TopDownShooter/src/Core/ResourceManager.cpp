#include "ResourceManager.h"

ResourceManager::ResourceManager() 
 : textureContainer("res/textures/"),
   fontContainer("res/fonts/"),
   soundBufferContainer("res/audio/") {}

ResourceManager & ResourceManager::getInstance() {
	static ResourceManager instance;
	return instance;
}
