#pragma once

#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape ButtonShape;
	sf::Text ButtonText;
	sf::Sprite ButtonFrame;
	sf::Texture ButtonTexture;
	sf::Font font;
	bool isCorrect = false;
	int count = 0;

public:
	Button();
	void initialize(sf::Font t_font);
	void draw(sf::RenderWindow& t_window);
	sf::Text getQuestion() { return ButtonText; };
	void setupShape(sf::RenderWindow& t_window);
	void setupFrame();
	void setPosition(int t_i, sf::RenderWindow& t_window);
	bool checkForMouseHover(sf::Vector2f t_point);
	void checkForMouseClick(sf::Vector2f t_point); 
	void setAnswerText(std::string t_currentAnswer);


};

