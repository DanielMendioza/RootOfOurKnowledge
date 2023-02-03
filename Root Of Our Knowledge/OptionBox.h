#pragma once
#include <SFML/Graphics.hpp>

class OptionBox
{
private:
	sf::Sprite BoxSprite;
	sf::Texture BoxTexture;
	sf::RectangleShape m_box;
	bool ifCorrect;
public:
	sf::RectangleShape getShape() { return m_box; }
	bool CheckIfCorrect() { return ifCorrect; }
};

