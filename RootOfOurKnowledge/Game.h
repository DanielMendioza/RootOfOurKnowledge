#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "button.h"
#include "QuestionRect.h"

class Game
{
public:
    Game();
    void Run();

private:
    void initialize();
    void processEvents();
    int getStages() { return m_stages; }
    void update(sf::Time deltaTime);
    void draw();
    void setAnswers();
    void setupQuestions(QuestionRect t_currentQuestion, sf::RenderWindow& t_window);
   
    std::string AllQuestions[10]{
            "1","2","3","4","5","6","7","8","9","10"
    };

    std::string AllAnswers[4]{
        "yes", "no", "quite", "yesn't"
    };
    sf::RenderWindow mWindow;
    sf::Vector2f t_point;
    sf::Font m_theFont;
    sf::Texture m_QuestionFrame;
    sf::Texture m_host;
    sf::Texture m_background;
    sf::Texture m_answerframe;
    int m_stages = 0;

    enum stages
    {
        start,
        rounds,
        end1,
        end2
    };

    static const sf::Time TimePerFrame;
};

#endif //GAME_H