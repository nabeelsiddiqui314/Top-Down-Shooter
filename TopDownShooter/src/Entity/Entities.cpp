#include "Entities.h"
#include "Entity.h"
#include <ctime>

Entities::Entities()
	: m_spriteRenderer(std::make_shared<SpriteSortRenderer>()),
	m_entityManager(std::make_shared<EntityManager>()),
	m_entityfactory(m_spriteRenderer, m_entityManager) {}

void Entities::create() {
	m_entityManager->addEntity(m_entityfactory.createPlayer());

	srand(time(NULL)); // test code .... 

	for (int i = 0; i < 5; i++) {
		int x = rand() % 700;
		int y = rand() % 500;

		bool isWall = rand() % 2;
		std::string name = (isWall ? "wall" : "wall");
		
		m_entityManager->addEntity(m_entityfactory.createStaticObject(name, x, y));
	} // test end
}

void Entities::update(float deltaTime) {
	m_entityManager->update(deltaTime);
}

void Entities::render(sf::RenderWindow& window) {
	m_spriteRenderer->renderSprites(window);
}