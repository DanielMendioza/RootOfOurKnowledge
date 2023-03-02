#include "TheHost.h"

void TheHost::initialize(sf::Texture& t_host)
{
	theHostTexture = t_host;
	theHostSprite.setTexture(theHostTexture);
	theHostSprite.setTextureRect(sf::IntRect(0, 0, 73, 192));
}

void TheHost::draw(sf::RenderWindow& t_window)
{
	t_window.draw(theHostSprite);
}

void TheHost::SetupHost(sf::RenderWindow& t_window)
{
	theHostSprite.setOrigin(theHostSprite.getGlobalBounds().width / 2, theHostSprite.getGlobalBounds().height / 2);
	theHostSprite.setPosition(t_window.getSize().x -245, (((theHostSprite.getGlobalBounds().height / 4)*3)+400));
	theHostSprite.setScale(4.5, 4.5);
}
