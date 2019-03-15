#pragma once
#include <Entity/Orcs.hpp>
#include <Entity/Entity.hpp>
#include "Level.hpp"

class OrcLevel :
	public Level
{
public:
	OrcLevel(sf::RenderWindow * window, std::stack<Level*>* level);
	virtual ~OrcLevel();

	// Inherited via Level
	virtual void update(const float & deltaTime) override;
	virtual void render(sf::RenderTarget & target) override;

private:
	void initLevel();
	void spawnOrcs();
	void renderOrcs();

	std::vector<Orcs*> mOrcs;
	std::vector<sf::Texture> mOrcTextures;

	sf::Texture mBackgroundTexture;
	sf::Sprite mBackgroundSprite;
};

