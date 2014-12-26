#include "Header.h"

/////////////////////////get a game reset function and get scores saved//////////////////////////

int _tries;
int _winTrigger;
#define maxim 20

void main()
{
	char cReset = 'n';

	do
	{

		int maxTries = 15;	
		int wins = 0;
		int losses = 0;
		int best = 15;
	
		//////////////////////////////////////////////////////////////////////////
		_winTrigger = 0;
		_tries = 0;
		
		OpenScores(&wins, &losses, &best);//pulls 
		DisplayMenu(&wins, &losses, &best);

		////////get max tries here///////

		do
		{
			_tries++;
			GetGuess();		
		}while((_tries <= maxTries) && (_winTrigger == 0));//While you have tries left, and havent gotten a correct guess, get more guesses

		if (_winTrigger == 1)
		{
			printf("\n\nYou won.");
			wins++;
			if (best == 0)
				best = _tries;//since no amount of guesses can be less than zero, assume it is the first game. Overwrite it regardless
			if (_tries < best)
				best = _tries;//saves the new "best" round
		}
		else
		{
			printf("\n\nYou lost.");
			losses++;
		}
		
		SaveScores(wins, losses, best);

		do
		{
			printf("\n\n\n\n Would you like to play again? (Y/N): ");
			fflush(stdin);
			scanf("%c", &cReset);
			cReset = toupper(cReset);
		}while((cReset != 'Y') && (cReset != 'N'));

		system("cls");
	}while(cReset == 'Y');
	system("pause");
}