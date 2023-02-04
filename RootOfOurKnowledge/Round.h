#pragma once

#include <string>

class Round {
public:
	std::string m_question; // This is the question text

	std::string m_answers[4]; // These are the possible answers

	int m_correctAnswer; // This is the index of the right answer (0-3)

	bool TalkingTime;
	bool questionTime;
	void setAnswers(std::string t_question, std::string t_answer);
};