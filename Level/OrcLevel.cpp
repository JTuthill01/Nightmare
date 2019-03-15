#include "stdafx.hpp"
#include "OrcLevel.hpp"

OrcLevel::OrcLevel(sf::RenderWindow * window, std::stack<Level*>* level) : Level(window, level)
{
	this->initLevel();

	this->spawnOrcs();
}

OrcLevel::~OrcLevel()
{
}

void OrcLevel::update(const float & deltaTime)
{
	this->pPlayer.update(deltaTime);

	this->playerInput(deltaTime);

	for (size_t i = 0; i < this->mOrcs.size(); i++)
		this->mOrcs[i]->update(deltaTime);
}

void OrcLevel::render(sf::RenderTarget & target)
{
	target.draw(this->mBackgroundSprite);

	this->pPlayer.render(target);

	this->renderOrcs();
}

void OrcLevel::initLevel()
{
	if (!this->mBackgroundTexture.loadFromFile("Resources/Textures/Backgrounds/bitmap.png"))
	{
		std::cerr << "Level failed to fucking load" << "\n";

		EXIT_FAILURE;
	}

	this->mBackgroundSprite.setTexture(this->mBackgroundTexture);
}

void OrcLevel::spawnOrcs()
{
	sf::Texture temp;
	if (!temp.loadFromFile("Resources/Textures/Orcs/Combined.png"))
		std::cerr << "Orcs not found" << "\n";

	this->mOrcTextures.push_back(temp);

	this->mOrcs.push_back(new Orcs(this->mOrcTextures, sf::Vector2f(1700.F, 800.F), this->pWindow->getSize()));
}

void OrcLevel::renderOrcs()
{
	for (size_t i = 0; i < this->mOrcs.size(); i++)
		this->mOrcs[i]->render(*this->pWindow);
}
