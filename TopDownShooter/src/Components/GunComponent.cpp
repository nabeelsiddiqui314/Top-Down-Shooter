#include "GunComponent.h"
#include "../Entity/Blueprints/BulletBlueprint.h"
#include "../Events/GunFireEvent.h"
#include "TransformComponent.h"

GunComponent::GunComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, const sf::Vector2f& relativePos)
	: IComponent(parent),
	  m_parent(parent),
	  m_window(window),
      m_relativePosition(relativePos) {}

void GunComponent::init() {

}

void GunComponent::update(float deltaTime) {}

void GunComponent::handleEvent(const GunFireEvent& fireEvent) {
	auto transformComponent = m_transformComponent.lock();
	if (transformComponent) {
		sf::Vector2f pos;
		float rotation = transformComponent->getRotation() / 57.2958;

		pos.x = m_relativePosition.x * cosf(rotation) - m_relativePosition.y * sinf(rotation);
		pos.y = m_relativePosition.x * sinf(rotation) + m_relativePosition.y * cosf(rotation);

		pos.x += transformComponent->getPosition().x;
		pos.y += transformComponent->getPosition().y;

		std::unique_ptr<IBlueprint> bulletBlueprint =
			std::make_unique<BulletBlueprint>(m_parent, m_window, pos, rotation, fireEvent.velocity, fireEvent.bulletName);
		addEntityFromBlueprint(bulletBlueprint);
	}
}