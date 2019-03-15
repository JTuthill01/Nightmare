#include "stdafx.hpp"
#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<States*>* states) : States(window, states)
{
	this->initLevel();
}

GameState::~GameState()
{
	while (!this->mLevels.empty())
	{
		delete this->mLevels.top();
		this->mLevels.pop();
	}
}

void GameState::update(const float & deltaTime)
{
	if (!this->mLevels.empty())
		this->mLevels.top()->update(deltaTime);
}

void GameState::render(sf::RenderTarget * target)
{
	if (!this->mLevels.empty())
		this->mLevels.top()->render(*this->pWindow);
}

void GameState::initLevel()
{
	this->mLevels.push(new OrcLevel(this->pWindow, &this->mLevels));
}


