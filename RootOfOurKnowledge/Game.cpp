//
// created from scratch
//

#include "Game.h"
#include "button.h"
#include "QuestionRect.h"
#include "Round.h"
#include "TheHost.h"
#include "background.h"
#include <iostream>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
QuestionRect questionFrame;
Button answerFrame[4];
Round m_round[10];
TheHost theHost;
background bg;

Game::Game()
    : mWindow(sf::VideoMode(2880, 1620), "Your Awesome Game!")//current computer's resolution too big, use 4:3 ratio 
{
    initialize();
    bg.SetupBg(mWindow);
    questionFrame.setupShape(mWindow);
    for (size_t i = 0; i < 4; i++)
    {
        answerFrame[i].setupShape(mWindow);
    }
    theHost.SetupHost(mWindow);
}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        draw();
    }
}

void Game::initialize()
{
    if (!m_QuestionFrame.loadFromFile("ASSETS\\IMAGES\\QuestionFrame.png"))
    {
        std::cout << "Error, couldnt load question frame\n";
    }
    questionFrame.initialize(m_QuestionFrame);
    if (!m_background.loadFromFile("ASSETS\\IMAGES\\background.png"))
    {
        std::cout << "Error, couldnt load question frame\n";
    }
    if (!m_host.loadFromFile("ASSETS\\IMAGES\\theHost.png"))
    {
        std::cout << "Error, couldnt load question frame\n";
    }
    theHost.initialize(m_host);
    bg.initialize(m_background);
}

void Game::processEvents()
{
    sf::Event event{};

    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                t_point = (static_cast<sf::Vector2f>(sf::Mouse::getPosition(mWindow)));
                for (size_t i = 0; i < 4; i++)
                {
                    answerFrame[i].checkForMouseClick(t_point);
                }
            }
        case sf::Event::MouseMoved:
            for (size_t i = 0; i < 4; i++)
            {
                answerFrame[i].checkForMouseHover(t_point);
            }
        default:
            break;
        }

    }
}


void Game::update(sf::Time deltaTime)
{
    for (size_t i = 0; i < 4; i++)
    {
        answerFrame[i].setPosition(i, mWindow);
    }
    t_point = (static_cast<sf::Vector2f>(sf::Mouse::getPosition(mWindow)));
    
    // TODO: Update your objects here
    // Example: mWindow.draw(mPlayer);
}

void Game::draw()
{
    mWindow.clear(sf::Color::White);
    bg.draw(mWindow);//draws the background
    questionFrame.draw(mWindow);
    theHost.draw(mWindow);
    // TODO: Draw your objects here
   for (size_t i = 0; i < 4; i++)
    {
        answerFrame[i].draw(mWindow);
    }
    mWindow.display();
}

void Game::setAnswers()
{

}



void Game::setupQuestions(QuestionRect t_currentQuestion, sf::RenderWindow& t_window)
{
    for (size_t i = 0; i < 10; i++)
    {
        m_round[i].m_question = AllQuestions[i];
        for (size_t j = 0; j < 4; j++)
        {
            m_round[i].m_answers[j] = AllAnswers[j];
        }
    };
}
