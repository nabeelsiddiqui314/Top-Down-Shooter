#pragma once
#include <memory>
#include "IEntityFactory.h"

namespace sf {
	class RenderWindow;
}

class DefaultEntityFactory : public IEntityFactory {
public:
	DefaultEntityFactory(std::shared_ptr<sf::RenderWindow> window);
	~DefaultEntityFactory() = default;
public:
	std::shared_ptr<Entity> createPlayer() const override;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
};