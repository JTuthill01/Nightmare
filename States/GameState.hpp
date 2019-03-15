#pragma once
#include <Level/OrcLevel.hpp>
#include <Level/Level.hpp>
#include "States.hpp"

class GameState :
	public States
{
public:
	GameState(sf::RenderWindow* window, std::stack<States*>* states);
	virtual ~GameState();

	// Inherited via States
	virtual void update(const float & deltaTime) override;
	virtual void render(sf::RenderTarget * target = nullptr) override;

private:
	void initLevel();

	std::stack<Level*> mLevels;
};

