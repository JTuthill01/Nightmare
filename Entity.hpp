#pragma once
#include "Player.hpp"
#include "AnimationComponent.hpp"
#include "MovementComponent.hpp"

class Entity
{
public:
	Entity(sf::RenderWindow * window, std::stack<Entity*>* entity);
	~Entity();

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	virtual void updateAnimations(const float & deltaTime);
	virtual bool collision(sf::Sprite sprite);

	virtual void createMovementComponent(const float max_velocity, const float acceleration, const float deceleration);
	virtual void createAnimationComponent(sf::Texture & texture_sheet);
	virtual void move(const float direction_x, const float direction_y, const float & deltaTime);

protected:
	std::stack<Entity*>* pEntity;

	bool pIsAttacking;

	sf::RenderWindow* pWindow;
	sf::Sprite pSprite;
	sf::Texture pTexture;

	Player pPlayer;
	AnimationComponent* pAnimationComponent;
	MovementComponent* pMovementComponent;
};

