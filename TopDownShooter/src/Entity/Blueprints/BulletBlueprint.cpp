#include "BulletBlueprint.h"
#include "../../Utilities/ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include "../../Components/IComponent.h"
#include "../Entity.h"

BulletBlueprint::BulletBlueprint(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, 
	const sf::Vector2f& pos, const float rotation, const float velocity, const std::string& textureName)
  : m_parent(parent),
	m_window(window),
	m_pos(pos),
	m_rotation(rotation),
	m_velocity(velocity),
	m_textureName(textureName) {
}

std::shared_ptr<Entity> BulletBlueprint::getEntity() {
	auto bullet = std::make_shared<Entity>();

	return bullet;
}