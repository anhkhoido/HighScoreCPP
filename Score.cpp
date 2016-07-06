//
// File's name: Score.cpp 
// Author: Anh Khoi Do
// Date: 2016-07-04 17:30:00
// Version: 1.0
//
// Description: This is the implementation file of a
// class that represents the score of a player.
//
// REVISION HISTORY
//
// DATE           Author           VERSION     REASON(S)
// ----------------------------------------------------------
// 2016-07-04     Anh Khoi Do      1.0         Creation of the file.
//=================================================================================

#include "Score.h"


Score* Score::_instance = 0;

Score::Score() { _score = 0; }

Score::Score(int s)
{
	_score = s;
}


Score* Score::Instance()
{
	if (_instance == 0) _instance = new Score;
	else std::cout << "Unique reference to the score already exists." << std::endl;

	return _instance;
}


void Score::setScore(int s)
{
	_score = s;
}


int Score::getScore() const 
{
	return _score;
}

void Score::destroy()
{
	if (_instance != 0) {
		delete _instance;
		_instance = 0;
	} else std::cout << "The singleton for the score is already destroyed!" << std::endl;
}


std::ostream& Score::read(std::ostream& os) const
{
	os << "Score: " << _score << std::endl;

	return os;
}

std::ostream& operator<<(std::ostream& os, const Score& src) {
	src.read(os);

	return os;
}
