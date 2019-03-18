#pragma once
#include <Component/AnimationComponent.hpp>
#include <Component/MovementComponent.hpp>
#include <Entity/Player.hpp>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

protected:
	bool collision(sf::Sprite& sprite);

	void updateAnimations(sf::Sprite& sprite, const float& deltaTime);
	void initTextures(sf::Texture& texture, sf::Sprite& sprite, const std::string& filePath);
	void move(const float direction_x, const float direction_y, const float  & deltaTime);
	void createMovementComponent(const float max_velocity,
		const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	bool pIsAttacking;

	sf::Sprite pSprite;

	Player pPlayer;
	MovementComponent* pMovementComponent;
	AnimationComponent* pAnimationComponent;
};

