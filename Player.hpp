#pragma once

#include "AnimationComponent.hpp"
#include "MovementComponent.hpp"

class Player
{
public:
	Player();
	Player(float x, float y, sf::Texture& texture_sheet);
	~Player();

	void render(sf::RenderTarget& target);
	void update(const float& deltaTime);
	void updateAnimations(const float& deltaTime);
	void move(const float direction_x, const float direction_y, const float  & deltaTime);
	void startContact();
	void endContact();

	inline sf::FloatRect getGobalBounds()const { return this->mPlayerSprite.getGlobalBounds(); }
	inline sf::Vector2f getPosition() const { return this->mPlayerSprite.getPosition(); }

	bool IsAttacking() const { return mIsAttacking; }

protected:
	MovementComponent* pMovementComponent;
	AnimationComponent* pAnimationComponent;

	float pMovementSpeed;

private:
	bool mIsContact;
	bool mIsAttacking;

	int mKeyTime;
	float mRadius;

	void updateAttack();
	void createMovementComponent(const float max_velocity,
		const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	sf::Texture mPlayerTexture;
	sf::Sprite mPlayerSprite;
};

