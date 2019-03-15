#pragma once
#include "Entity.hpp"

class Orcs :
	public Entity
{
public:
	Orcs();
	Orcs(std::vector<sf::Texture> &texture, sf::Vector2f position, sf::Vector2u windowBounds);
	Orcs(sf::RenderWindow * window, std::stack<Entity*>* entity);
	virtual ~Orcs();

	// Inherited via Entity
	virtual void update(const float & deltaTime) override;
	virtual void render(sf::RenderTarget & target) override;

private:
	std::vector<sf::Texture>* mOrcTexture;
	sf::Sprite mOrcSprite;
	sf::Vector2u mWindowBounds;
};

