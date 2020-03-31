#pragma once
#include "IComponent.h"

namespace sf {
	class RenderWindow;
}

class GunComponent : public IComponent {
public:
	GunComponent(std::weak_ptr<Entity> parent, std::shared_ptr<sf::RenderWindow> window);
	~GunComponent() = default;
public:
	void update(float deltaTime) override;
	void handleEvent(const GunFireEvent& fireEvent) override;
private:
	const std::weak_ptr<Entity> m_parent;
	const std::shared_ptr<sf::RenderWindow> m_window;
};