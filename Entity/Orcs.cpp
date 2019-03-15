#include "stdafx.hpp"
#include "Orcs.hpp"

Orcs::Orcs() : Entity(pWindow, pEntity)
{
}

Orcs::Orcs(std::vector<sf::Texture>& texture, sf::Vector2f position, sf::Vector2u windowBounds) : Entity(pWindow, pEntity)
{
	this->mOrcTexture = &texture;
	this->mWindowBounds = windowBounds;

	this->mOrcSprite.setTexture((*this->mOrcTexture)[0]);
	this->mOrcSprite.setScale(-1.F, 1.F);
	this->mOrcSprite.setPosition(position);
}

Orcs::Orcs(sf::RenderWindow * window, std::stack<Entity*>* entity) : Entity(window, entity)
{
}

Orcs::~Orcs()
{
}

void Orcs::update(const float & deltaTime)
{
	this->mOrcSprite.move(-1.F, 0.F);
}

void Orcs::render(sf::RenderTarget & target)
{
	target.draw(this->mOrcSprite);
}
