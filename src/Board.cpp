
#include "Board.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <string>

int Board::player = 1;
int Board::counter = 0;

Board::Board() 
{
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++)
		{
			gameBoard[i][j] = '-';
		}
	}
}

//Takes the players turn
void Board::MakeMove(int row, int col)
{
	if (okMove(row, col))
	{
		if (player == 1)
		{
			gameBoard[row][col] = 'X';
			player++;
			counter++;
		}
		else if (player == 2)
		{
			gameBoard[row][col] = 'O';
			player--;
			counter++;
		}
	}
	else
	{
		int newRow, newCol;
		std::cout << "That Space Is already occupied please try again (0, 1, 2)";
		std::cin >> newRow >> newCol;
		MakeMove(newRow, newCol);
	}

}

//Takes the AI's Turn
void Board::AIMove(int row, int col)
{

	if (okMove(row, col))
	{
		if (player == 1)
		{
			gameBoard[row][col] = 'X';
			player++;
			counter++;
		}
		else if (player == 2)
		{
			gameBoard[row][col] = 'O';
			player--;
			counter++;
		}
	}
	else
	{
		int newRow = rand() % 3;
		int	newCol = rand() % 3;
		AIMove(newRow, newCol);
	}

}

//Checks if the game is over using a messy
//Algorithm
bool Board::gameOver()
{

	char a = Board::gameBoard[0][0];
	char b = Board::gameBoard[1][1];
	char c = Board::gameBoard[2][2];
	char e = Board::gameBoard[0][2];
	char f = Board::gameBoard[2][0];

	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;

	if ((((a == b) && (b == c)) || ((e == b) && (b == f))) && b != '-')
	{
		std::cout << std::endl <<  b  <<" won the game!" << std::endl;
		return false;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		if (Board::gameBoard[i][0] != '-')
			sum1 += Board::gameBoard[i][0];
		if (Board::gameBoard[i][1] != '-')
			sum2 += Board::gameBoard[i][1];
		if (Board::gameBoard[i][2] != '-')
			sum3 += Board::gameBoard[i][2];

	}

	if (sum1 == 264 || sum2 == 264 || sum3 == 264)
	{
		std::cout << std::endl <<   "X won the game!" << std::endl;
		return false;
	}
	else if (sum1 == 237 || sum2 == 237 || sum3 == 237)
	{
		std::cout << std::endl << "O won the game!" << std::endl;
		return false;
	}

	

	sum1 = 0;
	sum2 = 0;
	sum3 = 0;

	for (int j = 0; j < SIZE; j++)
	{
		if (Board::gameBoard[0][j] != '-')
			sum1 += Board::gameBoard[0][j];
		if (Board::gameBoard[1][j] != '-')
			sum2 += Board::gameBoard[1][j];
		if (Board::gameBoard[2][j] != '-')
			sum3 += Board::gameBoard[2][j];
	}

	if (sum1 == 264 || sum2 == 264 || sum3 == 264)
	{
		std::cout << std::endl << "X won the game!" << std::endl;
		return false;
	}
	else if (sum1 == 237 || sum2 == 237 || sum3 == 237)
	{
		std::cout << std::endl << "O won the game!" << std::endl;
		return false;
	}

	if (counter == 9){
		std::cout << std::endl << " Tie Game " << std::endl;
		return false;
	}
	return true;
}

bool Board::okMove(int row, int col)
{
	if (gameBoard[row][col] == '-')
		return true;
	else
		return false;
}

void Board::displayBoard(){
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << gameBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Board::~Board()
{
	delete [] gameBoard;
}
