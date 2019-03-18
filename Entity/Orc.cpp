#include "stdafx.hpp"
#include "Orc.hpp"

Orc::Orc() : mIsAttacking(false)
{
	this->initTextures();

	this->createMovementComponent(350.f, 16.f, 6.f);
	this->createAnimationComponent(this->mOrcTexture);

	this->mAnimationComponent->addAnimation("WALK", 5.f, 0, 0, 6, 0, 192, 192);
	this->mAnimationComponent->addAnimation("ATTACK", 5.f, 0, 2, 6, 2, 192, 192);
}

Orc::~Orc()
{
}

void Orc::update(const float & deltaTime)
{
	this->mMovementComponent->update(deltaTime);

	this->updateAnimations(deltaTime);

	this->collision();
}

void Orc::render(sf::RenderTarget & target)
{
	target.draw(this->mOrcSprite);
}

bool Orc::collision()
{
	if (this->mPlayer.getGobalBounds().intersects(this->mOrcSprite.getGlobalBounds()))
		return true;

	return false;
}

void Orc::updateAnimations(const float & deltaTime)
{
	if (this->collision())
	{
		this->mIsAttacking = true;

		//if (this->mOrcSprite.getScale().x > 0.f) //Facing left
		//	this->mOrcSprite.setOrigin(96.f, 0.f);

		this->mOrcSprite.setOrigin(350.f, 0.f);

		if (this->mAnimationComponent->play("ATTACK", deltaTime, true))
		{
			this->mIsAttacking = false;

			if (this->mOrcSprite.getScale().x > 0.f) //Facing left
				this->mOrcSprite.setOrigin(0.f, 0.f);


			else //Facing right
				mOrcSprite.setOrigin(258.f, 0.f);
		}
	}

	else	if (this->mMovementComponent->getState(MOVING))
	{
		if (this->mOrcSprite.getScale().x < 0.f)
		{
			this->mOrcSprite.setOrigin(0.f, 0.f);
			this->mOrcSprite.setScale(1.f, 1.f);
		}

		this->mAnimationComponent->play("WALK", deltaTime,
			this->mMovementComponent->getVelocity().x,
			this->mMovementComponent->getMaxVelocity());
	}


	else if (this->mMovementComponent->getState(MOVING))
	{
		if (this->mOrcSprite.getScale().x > 0.f)
		{
			this->mOrcSprite.setOrigin(140.f, 0.f);
			this->mOrcSprite.setScale(-1.f, 1.f);
		}

		this->mAnimationComponent->play("WALK", deltaTime,
			this->mMovementComponent->getVelocity().x,
			this->mMovementComponent->getMaxVelocity());
	}

	else if (this->mMovementComponent->getState(MOVING_UP))
		this->mAnimationComponent->play("JUMP", deltaTime,
			this->mMovementComponent->getVelocity().y,
			this->mMovementComponent->getMaxVelocity());

	else if (this->mMovementComponent->getState(FALLING_DOWN))
		this->mAnimationComponent->play("WALK", deltaTime,
			this->mMovementComponent->getVelocity().y,
			this->mMovementComponent->getMaxVelocity());
}

void Orc::initTextures()
{
	if (!this->mOrcTexture.loadFromFile("Resources/Textures/Orcs/Combined.png"))
		std::cerr << "Orc not found" << "\n";

	this->mOrcSprite.setTexture(this->mOrcTexture);
	this->mOrcSprite.setScale(-1.F, 1.F);
	this->mOrcSprite.setPosition(1600.F, 800.F);
	this->mOrcSprite.move(-0.5F, 0.F);
}

void Orc::move(const float direction_x, const float direction_y, const float & deltaTime)
{
	
}

void Orc::createMovementComponent(const float max_velocity, const float acceleration, const float deceleration)
{
	this->mMovementComponent = new MovementComponent(this->mOrcSprite, max_velocity, acceleration,
		deceleration);
}

void Orc::createAnimationComponent(sf::Texture & texture_sheet)
{
	this->mAnimationComponent = new AnimationComponent(this->mOrcSprite, texture_sheet);
}
