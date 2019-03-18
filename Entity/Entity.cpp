#include "stdafx.hpp"
#include "Entity.hpp"

Entity::Entity()
{

}

Entity::~Entity()
{
}

bool Entity::collision(sf::Sprite & sprite)
{
	if (sprite.getGlobalBounds().intersects(this->pPlayer.getGobalBounds()))
		return true;

	return false;
}

void Entity::updateAnimations(sf::Sprite& sprite, const float & deltaTime)
{
	this->pSprite = sprite;

	if (this->pIsAttacking)
	{
		if (sprite.getScale().x > 0.f) //Facing left
			sprite.setOrigin(96.f, 0.f);

		else //Facing right
			sprite.setOrigin(350.f, 0.f);

		if (this->pAnimationComponent->play("ATTACK", deltaTime, true))
		{
			this->pIsAttacking = false;

			if (sprite.getScale().x > 0.f) //Facing left
				sprite.setOrigin(0.f, 0.f);


			else //Facing right
				sprite.setOrigin(258.f, 0.f);
		}
	}

	else	if (this->pMovementComponent->getState(MOVING))
	{
		if (sprite.getScale().x < 0.f)
		{
			sprite.setOrigin(0.f, 0.f);
			sprite.setScale(1.f, 1.f);
		}

		this->pAnimationComponent->play("WALK", deltaTime,
			this->pMovementComponent->getVelocity().x,
			this->pMovementComponent->getMaxVelocity());
	}


	else if (this->pMovementComponent->getState(MOVING))
	{
		if (sprite.getScale().x > 0.f)
		{
			sprite.setOrigin(140.f, 0.f);
			sprite.setScale(-1.f, 1.f);
		}

		this->pAnimationComponent->play("WALK", deltaTime,
			this->pMovementComponent->getVelocity().x,
			this->pMovementComponent->getMaxVelocity());
	}

	else if (this->pMovementComponent->getState(MOVING_UP))
		this->pAnimationComponent->play("JUMP", deltaTime,
			this->pMovementComponent->getVelocity().y,
			this->pMovementComponent->getMaxVelocity());

	else if (this->pMovementComponent->getState(FALLING_DOWN))
		this->pAnimationComponent->play("WALK", deltaTime,
			this->pMovementComponent->getVelocity().y,
			this->pMovementComponent->getMaxVelocity());

}

void Entity::initTextures(sf::Texture & texture, sf::Sprite& sprite, const std::string & filePath)
{
	if (!texture.loadFromFile(filePath))
		std::cerr << "Failed load the fucking texture" << "\n";

	sprite.setTexture(texture);
}

void Entity::move(const float direction_x, const float direction_y, const float & deltaTime)
{
}

void Entity::createMovementComponent(const float max_velocity, const float acceleration, const float deceleration)
{
	this->pMovementComponent = new MovementComponent(this->pSprite, max_velocity, acceleration,
		deceleration);
}

void Entity::createAnimationComponent(sf::Texture & texture_sheet)
{
	this->pAnimationComponent = new AnimationComponent(this->pSprite, texture_sheet);
}
