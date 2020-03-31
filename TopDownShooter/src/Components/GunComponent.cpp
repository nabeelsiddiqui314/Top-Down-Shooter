#include "GunComponent.h"
#include "../Entity/Blueprints/BulletBlueprint.h"

GunComponent::GunComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window) 
	: IComponent(parent),
	  m_window(window) {}

void GunComponent::update(float deltaTime) {
	
}

void GunComponent::handleEvent(const GunFireEvent& fireEvent) {

}