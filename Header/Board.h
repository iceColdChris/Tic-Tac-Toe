
#ifndef BOARD_H
#define BOARD_H

const int SIZE = 3;


class Board{
public:

	Board();
	void MakeMove(int, int);
	void AIMove(int, int);
	bool gameOver();
	void displayBoard();
	~Board();
private:
	char gameBoard[SIZE][SIZE];
	bool okMove(int, int);

	static int counter;
	static int player;
};
#endif
