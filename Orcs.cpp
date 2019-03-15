#include "stdafx.hpp"
#include "Orcs.hpp"

Orcs::Orcs() : Entity(pWindow, pEntity)
{
}

Orcs::Orcs(std::vector<sf::Texture>& texture, sf::Vector2f position, sf::Vector2u windowBounds) : Entity(pWindow, pEntity)
{
	this->createMovementComponent(350.f, 16.f, 6.f);
	this->createAnimationComponent((*this->mOrcTexture)[0]);

	this->pAnimationComponent->addAnimation("WALK", 5.f, 0, 0, 6, 0, 192, 192);
	this->pAnimationComponent->addAnimation("ATTACK", 5.f, 0, 1, 6, 1, 192, 192);

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
	this->pMovementComponent->update(deltaTime);
	this->updateAnimations(deltaTime);
	this->collision(this->mOrcSprite);
}

void Orcs::render(sf::RenderTarget & target)
{
	target.draw(this->mOrcSprite);
}
