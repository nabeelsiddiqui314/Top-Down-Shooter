#pragma once
#include "IComponent.h"
#include <SFML/System/Clock.hpp>

class TimedLifetimeComponent : public IComponent {
public:
	TimedLifetimeComponent(std::weak_ptr<Entity> parent, float lifetime); // seconds
	~TimedLifetimeComponent() = default;
public:
	void update(float deltaTime) override;
private:
	const float m_lifetime;
	sf::Clock m_lifetimeClock;
};