#include "GunComponent.h"
#include "../Entity/Blueprints/BulletBlueprint.h"
#include "../Events/GunFireEvent.h"

GunComponent::GunComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, const sf::Vector2f& relativePos)
	: IComponent(parent),
	  m_parent(parent),
	  m_window(window),
      m_relativePosition(relativePos) {}

void GunComponent::update(float deltaTime) {}

void GunComponent::handleEvent(const GunFireEvent& fireEvent) {
	sf::Vector2f pos;
	pos.x = m_relativePosition.x * cosf(fireEvent.rotation) - m_relativePosition.y * sinf(fireEvent.rotation);
	pos.y = m_relativePosition.x * sinf(fireEvent.rotation) + m_relativePosition.y * cosf(fireEvent.rotation);

	pos.x += fireEvent.pos.x;
	pos.y += fireEvent.pos.y;

	std::unique_ptr<IBlueprint> bulletBlueprint = 
		std::make_unique<BulletBlueprint>(m_parent, m_window, pos, fireEvent.rotation, fireEvent.velocity, fireEvent.bulletTexture);
	addEntityFromBlueprint(bulletBlueprint);
}