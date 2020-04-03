#pragma once
#include "IComponent.h"
#include <SFML/System/Vector2.hpp>

namespace sf {
	class RenderWindow;
}

class GunComponent : public IComponent {
public:
	GunComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window, const sf::Vector2f& relativePos);
	~GunComponent() = default;
public:
	void update(float deltaTime) override;
	void handleEvent(const GunFireEvent& fireEvent) override;
private:
	const std::weak_ptr<Entity> m_parent;
	const std::shared_ptr<sf::RenderWindow> m_window;
	const sf::Vector2f m_relativePosition;
};