#include "background.h"


void background::initialize(sf::Texture& t_bg)
{
	bgTexture = t_bg;
	bgSprite.setTexture(bgTexture);
	bgSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1200));
}

void background::draw(sf::RenderWindow& t_window)
{
	t_window.draw(bgSprite);
}

void background::SetupBg(sf::RenderWindow& t_window)
{
	bgSprite.setOrigin(bgSprite.getGlobalBounds().width / 2, bgSprite.getGlobalBounds().height / 2);
	bgSprite.setPosition(t_window.getSize().x / static_cast<float>(2), t_window.getSize().y / static_cast<float>(2));
	bgSprite.setScale(1.5, 1.35);
}
