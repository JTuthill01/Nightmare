#pragma once
#include "Player.hpp"
#include "Entity.hpp"
#include "Orcs.hpp"

class Level
{
public:
	Level(sf::RenderWindow* window, std::stack<Level*>* level);
	~Level();

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	void playerInput(const float& deltaTime);
	
protected:
	std::stack<Level*>* pLevel;

	sf::RenderWindow* pWindow;

	std::stack<Entity*>* pEntity;

	Player pPlayer;
	Orcs pOrcs;
};

