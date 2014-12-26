#include "Header.h"


#define DEBUG

//Returns an array of 4 random integers
int * EasyGame()
{
  int i;
  int CPUArray[4];
 
  srand(time(NULL));//Set the seed based on the time
  for (i = 0; i <= 3; i++) //fill the array with random numbers from 1-4
  {	
	CPUArray[i] = rand()% 4 + 1;   
  }

  return CPUArray;
}

//testing purposes
//#ifdef DEBUG
int main() 
{
  int i;
  int CPUArray[4];
  
 
  printf("Ten random numbers in [1,4]\n");
 
  srand(time(NULL));
  for (i = 0; i <= 3; i++) 
  {
	CPUArray[i] = rand()% 4 + 1;
    printf("%d\n", CPUArray[i]);
  }
 
  
  system("pause");
}
#endif DEBUG