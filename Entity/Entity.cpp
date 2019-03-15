#include "stdafx.hpp"
#include "Entity.hpp"

Entity::Entity(sf::RenderWindow * window, std::stack<Entity*>* entity) : pWindow(window), pEntity(entity), pIsAttacking(false)
{
	
}

Entity::~Entity() = default;


void Entity::createMovementComponent(const float max_velocity, const float acceleration, const float deceleration)
{
	this->pMovementComponent = new MovementComponent(this->pSprite, max_velocity, acceleration,
		deceleration);
}

void Entity::createAnimationComponent(sf::Texture & texture_sheet)
{
	this->pAnimationComponent = new AnimationComponent(this->pSprite, texture_sheet);
}

void Entity::move(const float direction_x, const float direction_y, const float & deltaTime)
{
	if (this->pMovementComponent)
		this->pMovementComponent->move(direction_x, direction_y, deltaTime);
}

void Entity::update(const float & deltaTime)
{
}

void Entity::updateAnimations(const float & deltaTime)
{
	if (this->pMovementComponent->getState(MOVING))
		this->pAnimationComponent->play("WALK", deltaTime,
			this->pMovementComponent->getVelocity().x,
			this->pMovementComponent->getMaxVelocity());

	if (this->pMovementComponent->getState(ATTACK))
		this->pAnimationComponent->play("ATTACK", deltaTime);
}

bool Entity::collision(sf::Sprite sprite)
{
	if (sprite.getGlobalBounds().intersects(this->pPlayer.getGobalBounds()))
		return true;

	return false;
}
