//
// File's name: Client.cpp
// Author: Anh Khoi Do
// Date: 2016-07-05
// Version: 1.0
// 
// Description: This is the client file of a program that accepts
// a number inputted by the user and stores it into a text file.
// Afterwards, the program displays the number inputted by the user
// and the highest inputted number of all time.
//
// REVISION HISTORY
//
// DATE           AUTHOR           VERSION     REASONS
// -------------------------------------------------------------------
// 2016-07-05     Anh Khoi Do      1.0         Creation of the file.
//

#include <iostream>
#include <fstream>
#include "Score.h"


int getNumberOfLines();
int getHighScore();
void selectionSort(int arr[], int size);

void quick(int arr[], int left, int right);


//
// The main function.
//
int main()
{

	//
	// Declaratioin of two instance variables.
	// The one named number will store the
	// number inputted by the user when the program
	// starts. The second one named highScore
	// stores the highest number ever inputted
	// by the user.
	//
	int number, highScore;

	Score* playerScore;
	playerScore = Score::Instance();
		
  //
	// Declaration of a file output stream.
	// It is responsible for entering data
	// into a file named highScore.txt. This file
	// stores all the numbers the user has inputted.
	//
	std::ofstream outputStream;
	outputStream.open("highScore.txt", std::ios::app);


	//
	// Message: It prompts the user to enter
	// a number.
	//
	if(outputStream.is_open()) {
	
		std::cout << "Enter a number: ";
		std::cin >> number;
		playerScore = new Score(number);
		outputStream << playerScore->getScore() << std::endl;
		
	} else std::cout << "Error in the program." << std::endl;

	//
	// Close the file output stream.
	//
	outputStream.close();

	//
	// Retrieve the highest inputted
	// number of all time and store
	// it into my local integer
	// variable named highScore.
	//
	highScore = getHighScore();

	std::cout << "Your input: " << playerScore->getScore() << std::endl;

	std::cout << "Highest input of all time: " << highScore << std::endl;
	
	playerScore->destroy();

	return 0;

}


//
// This member function returns the number
// of lines in a text file.
//
int getNumberOfLines()
{
	std::ifstream fin;
	int numberOfLines = 0, next;

	fin.open("highScore.txt");
	
	if (fin.is_open()) while (fin >> next) numberOfLines++;
	else std::cout << "Error while opening highScore.txt or finding it." << std::endl;

	fin.close();

	return numberOfLines;
}



//
// This member function looks through the file
// that stores the scores inputted by the user
// throughout time and populates an array of
// integers. Afterwards, it sorts that array
// and returns the last element of the array,
// which is the highest score.
//
int getHighScore()
{
	int highScore;
	int lines = getNumberOfLines();
	int next;
	int myArray[lines];


	std::ifstream input;
	input.open("highScore.txt");

	if (input.is_open())
	{
		for (int i = 0; i < lines && !input.eof(); i++)
		{
			input >> next;
			myArray[i] = next;
		}
	} else std::cout << "Error while opening highScore.txt or unable to find it." << std::endl;

	input.close();
	
	quick(myArray, 0, lines - 1);


	highScore = myArray[lines - 1];

	return highScore;
}



void selectionSort(int arr[], int size)
{
	int minIdx;
	int tmp;

	for (int i = 0; i < size; i++)
	{
		minIdx = i;
		
		for (int j = i; j < size; j++) if (arr[j] < arr[minIdx]) minIdx = j;

		tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;
	}
}

void quick(int arr[], int left, int right)
{
		int i = left;
		int j = right;
		int tmp;
		int pivot = arr[(left + right) / 2];

		while (i <= j) {
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i <= j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			}

		}

		if (left < j) quick(arr, left, j);
								
		if (i < right) quick(arr, i, right);
}
