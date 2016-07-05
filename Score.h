//
// File's name: Score.h
// Author: Anh Khoi Do
// Date: 2016-07-04 17:30:00
// Version: 1.0
// 
// Description: This is the header file of a class
// that represents the score of a player.
//
// REVISION HISTORY
//
// DATE          AUTHOR             REASONS
// ------------------------------------------------------------
// 2016-07-04    Anh Khoi Do        Creation of the file.
//
//=============================================================

#include <iostream>
#include <string>

#ifndef _SCORE_H_
#define _SCORE_H_


class Score
{	
	private:
		int _score;
		static Score* _instance;

	protected:
		Score();

	public:
		static Score* Instance();
		Score(int);
		void setScore(int s);
		int getScore() const;

		static void destroy();

		std::ostream& read(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Score& src);
#endif
