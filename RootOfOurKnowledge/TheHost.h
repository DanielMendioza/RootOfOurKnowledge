#pragma once
#include <SFML/Graphics.hpp>
class TheHost
{
private:
	sf::Sprite theHostSprite;
	sf::Texture theHostTexture;
	
public:
	void initialize(sf::Texture& t_host);
	void draw(sf::RenderWindow& t_window);
	void SetupHost(sf::RenderWindow& t_window);
};

