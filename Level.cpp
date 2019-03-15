#include "stdafx.hpp"
#include "Level.hpp"

Level::Level(sf::RenderWindow * window, std::stack<Level*>* level) : pWindow(window), pLevel(level){}

Level::~Level() = default;

void Level::playerInput(const float & deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->pPlayer.move(1.F, 0.F, deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->pPlayer.move(-1.F, 0.F, deltaTime);
}



