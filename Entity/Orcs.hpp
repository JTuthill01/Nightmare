#pragma once
#include "Entity.hpp"

class Orcs :
	public Entity
{
public:
	Orcs();
	virtual ~Orcs();

	// Inherited via Entity
	virtual void update(const float & deltaTime) override;
	virtual void render(sf::RenderTarget & target) override;

private:
	sf::Sprite mOrcSprite;
	sf::Texture mOrcTexture;
};

