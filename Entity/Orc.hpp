#pragma once
#include <Component/AnimationComponent.hpp>
#include <Component/MovementComponent.hpp>
#include <Entity/Player.hpp>

class Orc
{
public:
	Orc();
	~Orc();

	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);

private:
	bool collision();

	void updateAnimations(const float& deltaTime);
	void initTextures();
	void move(const float direction_x, const float direction_y, const float  & deltaTime);
	void createMovementComponent(const float max_velocity,
		const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	bool mIsAttacking;

	sf::Texture mOrcTexture;
	sf::Sprite mOrcSprite;

	Player mPlayer;
	MovementComponent* mMovementComponent;
	AnimationComponent* mAnimationComponent;
};

