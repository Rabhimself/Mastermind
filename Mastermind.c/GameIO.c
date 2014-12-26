#include "Header.h"

void OpenScores(int *wins, int *losses, int *best)
{
	FILE * oFile;
	oFile = fopen ("myfile.txt","r");
	
	if (oFile == NULL) 
	{
         *wins = 0;
		 *losses = 0;
		 *best = 0;
    }
	else
	{
		fscanf(oFile,"%d %d %d", wins, losses, best);
		fclose(oFile);
	}

	
}

void SaveScores(int wins, int losses, int best)
{

	FILE * sFile;

	sFile = fopen ("myfile.txt","w");	
	fprintf(sFile ,"%d %d %d", wins, losses, best);	 
	      if (sFile == NULL) {
			  system("pause");
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }
	fclose(sFile);
  
}