#include "stdafx.hpp"
#include "Orcs.hpp"

Orcs::Orcs()
{
	this->initTextures(this->mOrcTexture, this->mOrcSprite, "Resources/Textures/Orcs/Combined.png");

	this->mOrcSprite.setPosition(1700.F, 750.F);
	this->mOrcSprite.setScale(-1.F, 1.F);

	this->createMovementComponent(350.f, 16.f, 6.f);
	this->createAnimationComponent(this->mOrcTexture);

	this->pAnimationComponent->addAnimation("WALK", 5.f, 0, 1, 6, 1, 192, 192);
	this->pAnimationComponent->addAnimation("ATTACK", 5.f, 0, 2, 6, 2, 192, 192);
}

Orcs::~Orcs()
{
}

void Orcs::update(const float & deltaTime)
{
	this->pMovementComponent->update(deltaTime);

	this->updateAnimations(this->mOrcSprite, deltaTime);

	this->collision(this->mOrcSprite);
}

void Orcs::render(sf::RenderTarget & target)
{
	target.draw(this->mOrcSprite);
}
