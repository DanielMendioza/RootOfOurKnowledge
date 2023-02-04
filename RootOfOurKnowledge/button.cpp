
#include "button.h"
#include <iostream>

Button::Button()
{
}

void Button::initialize(sf::Font t_font)
{
	font = t_font;
}

void Button::draw(sf::RenderWindow& t_window)
{
	t_window.draw(ButtonShape);
	t_window.draw(ButtonText);
}

void Button::setupShape(sf::RenderWindow& t_window)
{
	ButtonShape.setSize(sf::Vector2f(t_window.getSize().x / 3 - 60, t_window.getSize().y / 4- 80));
}

void Button::setupFrame()
{
	ButtonFrame.setTexture(ButtonTexture);
}

void Button::setPosition(int t_i, sf::RenderWindow& t_window)
{
	{
		switch (t_i)
		{
		case 0://offset is 40 on each side
			ButtonShape.setPosition(40.0f , ((t_window.getSize().y / static_cast<float>(4)) * 2) + 40);
			break;
		case 1:
			ButtonShape.setPosition((t_window.getSize().x / static_cast<float>(3)) + 40, ((t_window.getSize().y / static_cast<float>(4)) * 2) + 40);
			break;
		case 2:
			ButtonShape.setPosition(40.0f, ((t_window.getSize().y / static_cast<float>(4)) * 3) + 40);
			break;
		case 3:
			ButtonShape.setPosition((t_window.getSize().x / static_cast<float>(3)) + 40, ((t_window.getSize().y / static_cast<float>(4)) * 3) + 40);
			break;
		}
	}
}

bool Button::checkForMouseHover(sf::Vector2f t_point)
{
	if (ButtonShape.getGlobalBounds().contains(t_point)) // Returns true/fals)
	{
		ButtonShape.setFillColor(sf::Color(229, 201, 45));
		return true;
	}
	else
	{
		ButtonShape.setFillColor(sf::Color(72, 62, 36));
		return false;
	}
	
}
void Button::checkForMouseClick(sf::Vector2f t_point)
{
	if (ButtonShape.getGlobalBounds().contains(t_point))
	{
		ButtonShape.setFillColor(sf::Color::Yellow);
		count++;
		std::cout << count << std::endl;
	}
}

void Button::setAnswerText(std::string t_currentAnswer)
{
	ButtonText.setString(t_currentAnswer);
	ButtonText.setOrigin(ButtonShape.getGlobalBounds().width / 2, ButtonShape.getGlobalBounds().height / 2);
	ButtonText.setPosition(ButtonText.getGlobalBounds().width / 2, ButtonText.getGlobalBounds().height / 2);
	ButtonText.setFont(font);
}
