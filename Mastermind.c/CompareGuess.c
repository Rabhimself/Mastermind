#include "Header.h"

#define TRUE 1
#define FALSE 0

void GetGuess()
{
	char playerGuess[5] ;	
	char c;
	int done = FALSE;

	do
	{
		char * ptrChk;
		int correctCount = 0;
		int j, i = 0;
		//get a string//
		printf("\n\nTry #%d. Guess the pins (eg:RGBY): ", _tries);
		fflush(stdin);
		fgets(playerGuess, 5, stdin);

		// convert to upper // in a while
		while(playerGuess[i])
		{
			c = playerGuess[i];
			playerGuess[i] = (toupper(c));
			i++;
		}
			//confirm all 4 are a valid char
		for(j = 0; j < (signed)strlen(playerGuess); j++)
		{						
			ptrChk = strrchr(_colorPool, playerGuess[j]);//if the guess[j] is found in the color pool
			if(ptrChk != NULL)							//then ptrChk will not be null, if it isnt, up the counter
			{
				correctCount++;
				ptrChk = NULL;
			}
		}
		i++;
		if(correctCount == 4)//if you have all 4 valid characters, then continue on to the compare func
			done = TRUE;
		else
			printf("Invalid guess.");
	}while(done == FALSE);

	CompareGuess(playerGuess);
}


void CompareGuess(char * guess)
{
	int i, j;
	char * playerGuess;
	int correctCounter[4] = {0,0,0,0};
	int blckPinCnt = 0;

	playerGuess = guess;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if((playerGuess[i]== _cpuPins[j]) && (i == j))///// if the values and locations are the same, black pin//////////////
			{
				correctCounter[i] = 2;				
			}
			else if((playerGuess[i] == _cpuPins[j]) && (correctCounter[i] != 2))///////// if values are the same, and there is no black pin in that slot///////
			{
				correctCounter[i] = 1;////then put a white pin in that slot/////////////			
			}
		}
	}

	printf("\t\tMatches:");
	printf("\n\t\t1234\n\t\t");

	for(i = 0; i < 4; i++)
	{
		//////prints the pin colors//////////
		switch (correctCounter[i])
		{
		case 0:
			printf(" ");
			break;
		case 1:
			printf("W");
			break;
		case 2:
			printf("B");
			blckPinCnt++;
			break;
		}
		/////////// if there are 4 black pins counted in the loop, up the winTrigger/////////////////////
		if(blckPinCnt == 4)
		{
			_winTrigger++;
		}
	}

}
