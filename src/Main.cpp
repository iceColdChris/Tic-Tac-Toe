#include "Board.h"
#include "AI.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>

void main(){
	Board b = Board();
	AI<Board> a = AI<Board>();

	bool bflag;

	srand(time(0));

	do{
		bflag = b.gameOver();

		b.displayBoard();
		int row, col;
		std::cout << "Please Enter Coordinates (0, 1, 2) ";
		std::cin >> row >> col;

		if (row >= 3 || col >= 3)
		{
			std::cout << "Please Enter valid coordinates (0, 1, 2) ";
			std::cin >> row >> col;
		}

		b.MakeMove(row, col);

		std::cout << std::endl;

		bflag = b.gameOver();


		a.turnDecision(b);

	} while (bflag);

	system("pause");
}