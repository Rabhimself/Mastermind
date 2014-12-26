#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void GameBuilder(int choice);
void CompareGuess();
void GetGuess();
void DisplayMenu(int *wins, int *losses, int *best);
void SaveScores(int wins,int losses,int best);
void OpenScores(int *wins, int *losses, int *best);
int SetTries();

extern char _cpuPins[4];
extern char _colorPool[5];
extern int _winTrigger;
extern int _tries;