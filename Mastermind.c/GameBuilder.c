#include "Header.h"

char _cpuPins[4];
char _colorPool[5] = {'R','B','G','Y',' '};

void GameBuilder(int choice)
{
  int i;

  //copies the color pool to the global array of cpuPins, if easy is picked, this is just shuffled to avoid dupes
  memcpy(_cpuPins, _colorPool, sizeof(_cpuPins));

 //set the seed for rand()
  srand((unsigned)time(NULL));

  //Now shuffle them, go from 0 to 3 in the array and swap them with one of the others
  //chosen at random
  if(choice == 1)
  {	  
	  for (i = 0; i <= 3; i++) 
	  {	
		int r, temp;
		r = rand()% 3 + 1;
		temp = _cpuPins[i];
		_cpuPins[i] = _cpuPins[r];
		_cpuPins[r] = temp;
	  }
	  //printf("%s", _cpuPins); /////test print
  }
  else
  {
	  for (i = 0; i <= 3; i++) 
	  {	
		int r;
		r = rand() % choice + 1;   
		_cpuPins[i] = _colorPool[r];
	  }
	  //printf("%s", _cpuPins); //////test print
  }
}//end func

//Sets max tries
int SetTries()
{
	int tries;

	do
	{
	printf(" How many tries do you want? (Max of 15): ");
	fflush(stdin);
	scanf_s("%d", &tries);
	}while((tries < 1) || (tries > 15));

	return tries;
}
