#include "GunComponent.h"
#include "../Entity/Blueprints/BulletBlueprint.h"
#include "../Events/GunFireEvent.h"

GunComponent::GunComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window) 
	: IComponent(parent),
	  m_parent(parent),
	  m_window(window) {}

void GunComponent::update(float deltaTime) {
	
}

void GunComponent::handleEvent(const GunFireEvent& fireEvent) {
	std::unique_ptr<IBlueprint> bulletBlueprint = 
		std::make_unique<BulletBlueprint>(m_parent, m_window, fireEvent.pos, fireEvent.velocity, fireEvent.bulletTexture);
	addEntityFromBlueprint(bulletBlueprint);
}