#include "QuestionRect.h"

QuestionRect::QuestionRect()
{
}

void QuestionRect::initialize(sf::Texture& t_frame)
{
	questionFrame.setTexture(t_frame);
}

void QuestionRect::draw(sf::RenderWindow& t_window)
{
	t_window.draw(questionFrame);
}

void QuestionRect::setupShape(sf::RenderWindow& t_window)
{
	questionFrame.setOrigin(questionFrame.getGlobalBounds().width / 2, questionFrame.getGlobalBounds().height / 2);
	questionFrame.setPosition(t_window.getSize().x / static_cast<float>(2), (questionFrame.getGlobalBounds().height / 2 + 200));
	questionFrame.setScale(2.5, 2.5);
	questionFrame.setTextureRect(sf::IntRect(0, 0, 478, 115));
}

