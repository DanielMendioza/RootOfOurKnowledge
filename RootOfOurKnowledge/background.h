#pragma once
#include <SFML/Graphics.hpp>

class background
{
private:
	sf::Sprite bgSprite;
	sf::Texture bgTexture;
public:
	void initialize(sf::Texture& t_bg);
	void draw(sf::RenderWindow& t_window);
	void SetupBg(sf::RenderWindow& t_window);
};

