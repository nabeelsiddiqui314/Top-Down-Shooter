#pragma once
#include "IBlueprint.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class BulletBlueprint : public IBlueprint {
public:
	BulletBlueprint(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, const sf::Vector2f& pos,
		const float position, const float velocity, const std::string& textureName);
	~BulletBlueprint() = default;
public:
	std::shared_ptr<Entity> getEntity() override;
private:
	const std::weak_ptr<Entity> m_parent;
	const std::shared_ptr<sf::RenderWindow> m_window;
	const sf::Vector2f m_pos;
	const float m_rotation;
	const float m_velocity;
	const std::string m_textureName;
};