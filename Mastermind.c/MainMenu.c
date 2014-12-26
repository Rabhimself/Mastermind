#include "Header.h"

void DisplayMenu(int *wins, int *losses, int *best)
{
	int iSelection = 0;
	int iWins, iLosses, iBest;
	iWins = *wins;
	iLosses = *losses;
	iBest = *best;

	printf("\t\t***********************************************\n");
	printf("\t\t*           Welcome to Mastermind             *\n");
	printf("\t\t***********************************************\n");
	printf("\t\t*       Wins: %-3d  Losses: %-3d  Best: %-3d     * \n", iWins,iLosses ,*best );
	printf("\t\t***********************************************\n\n");

	SetTries();

	printf("1 : Easy\n");
	printf("2 : Medium\n");
	printf("3 : Hard\n");

	do
	{
		printf("Pick your difficulty: ");
		fflush(stdin);
		scanf_s("%d", &iSelection);
	}while((iSelection < 1)||(iSelection > 3));

	switch(iSelection)
	{
		case 1:
			GameBuilder(1);
			break;
		case 2:
			GameBuilder(3);//integer passed also controls the scope of the color pool
			break;
			//setup a medium game
		case 3:
			GameBuilder(4);//same here, the 4 lets the game pull the blank space from the pool
			break;
			//setup a hard game
	}
}
