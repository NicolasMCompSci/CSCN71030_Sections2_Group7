// CSCN71030 - winter 2023
// Group Project - Tournament Bracket Generator
// Nicolas Masquieto, Ethan Groen, Louis He

// Implementations to the file saving and loading functions

#include "FileIO.h"
#include "Error.h"
#include <stdio.h>
#include <stdlib.h>

#define ARR_START_SIZE 2

// saves file. char[] is file name
void Save(PARTICIPANT tournament[], char filename[]) {
	// Declare file pointer and use filename to open the file where data
	// will be saved.	If unable to open file send an error message and exit.
	FILE* fp;
	if ((fp = fopen(filename, "wb")) == NULL)
		Print_Exit("An error ocurred while opening a file to save.");

	// Calculate the number of participants in array.
	int participantCount = sizeof(tournament) / sizeof(PARTICIPANT);
	// Save tournament participants to file sequentially.
	for (int i = 0; i < participantCount; i++)
		fwrite(&tournament[i], sizeof(PARTICIPANT), 1, fp);

	// Give user feedback when successful save happens.
	printf("Saved.");
	// Close file as it is no longer being used.
	fclose(fp);

}
// loads file with char[] name
PARTICIPANT* Load(char filename[]) {

	FILE* fp;
	if ((fp = fopen(filename, "rb")) == NULL)
		Print_Exit("An error ocurred while trying to open load file.");

	// Default empty tournament with the smallest size
	PARTICIPANT* tempTournament;
	if (tempTournament = (PARTICIPANT*)malloc(ARR_START_SIZE * sizeof(PARTICIPANT)))
		Print_Exit("Error allocating memory to tournament array.");
	
	// variable to add participant to tournament
	PARTICIPANT* p;
	if (p = (PARTICIPANT*)malloc(sizeof(PARTICIPANT)) == NULL)
		Print_Exit("An error ocurred while allocating memory to participant.");

	for (int i = 0; fread(p, sizeof(PARTICIPANT), 1, fp) == 1; i++) {
		tempTournament[i] = *p;
	}

	free(p);
	fclose(fp);

	return tempTournament;
}