#include "TimedLifetimeComponent.h"

TimedLifetimeComponent::TimedLifetimeComponent(std::weak_ptr<Entity> parent, float lifetime)
 : IComponent(parent),
   m_lifetime(lifetime) {}

void TimedLifetimeComponent::update(float deltaTime) {
	if (m_lifetimeClock.getElapsedTime().asSeconds() > m_lifetime) {
		destroyParent();
	}
}