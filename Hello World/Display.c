// CSCN71030 - winter 2023
// Author: Nicolas Masquieto
// 
// Implementation for display functions

#include "Display.h"
#include <stdio.h>
#include <stdarg.h>

// Displays a menu of variable size according to optionCount.
// Every new option prompt is another line.
void PrintMenu(int optionCount, char option[], ...)
{
	va_list valist;
	// allocate memory and inilialize list
	va_start(valist, option);

	// iterates through optionCount number of arguments
	// optionCount is subtracted by one to turn it into an index
	printf("%s\n", option);
	for (int i = 0; i < optionCount - 1; i++)
		printf("%s\n", va_arg(valist, char*));

	// clean memory reserved for list
	va_end(valist);
}

// Displays the tournment bracket.
void DisplayTournament_Short(PARTICIPANT tournament[], size_t participantCount) {
	// loops through the array, incrementing the player count by 2 every iteration
	// as 2 players are printed at the same time.
	for (int player = 0, round = 1; player < participantCount; player+=2, round++)
		printf("Match %d: %s vs %s\n", round, tournament[SearchTournament(tournament, participantCount, player+1)].name, 
				tournament[SearchTournament(tournament, participantCount, player+2)].name);
}

// Searches the tournament for the index of a participant according to their ID
// if ID searched is not found in any participant return -1
int SearchArrayIndexFromID(PARTICIPANT tournament[], size_t tournamentSize, int searchID) {
	// initialize temporary index to 0 for safety
	int realIndex = 0;
	for (; realIndex <= tournamentSize && tournament[realIndex].id != searchID; realIndex++);

	// if ID is not found in array, return -1
	if (realIndex > tournamentSize)
		return -1;
	else	// returns index
		return realIndex;
}