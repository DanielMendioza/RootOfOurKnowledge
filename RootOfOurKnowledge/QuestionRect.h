#pragma once
#include <SFML/Graphics.hpp>
class QuestionRect
{
private:
	sf::Text question;
	sf::Sprite questionFrame;

public:
	QuestionRect();
	void initialize(sf::Texture& t_frame);
	void draw(sf::RenderWindow& t_window);
	void setupShape(sf::RenderWindow& t_window);
	
};

