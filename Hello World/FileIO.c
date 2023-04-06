// CSCN71030 - winter 2023
// Group Project - Tournament Bracket Generator
// Nicolas Masquieto, Ethan Groen, Louis He

// Implementations to the file saving and loading functions

#define _CRT_SECURE_NO_WARNINGS
#include "FileIO.h"
#include "Error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_START_SIZE 2

// Saves tournament of participants to file.
// must pass the size as an int and the file name as a string
// returns false if a problem occured while saving
bool Save(PARTICIPANT *tournament, int participantCount, char filename[]) {
	// checks if filename is valid
	if (!IsValidFileName(filename))
		return false;

	// Declare file pointer and use filename to open the file where data
	// will be saved.	If unable to open file send an error message and exit.
	FILE* fp;
	if (!(fp = fopen(filename, "wb")))
		return false;

	// Save tournament participants to file sequentially.
	for (int i = 0; i < participantCount; i++)
		fwrite(&tournament[i], sizeof(PARTICIPANT), 1, fp);

	// Close file as it is no longer being used.
	fclose(fp);

	// returns true on a successful save
	return true;
}

// loads file with char[] name, pass an integer to get the tournament size
// returns false if file failed to load
bool Load(PARTICIPANT* savedTournament, int *tournamentSize, char filename[]) {
	// checks if file name is valid
	if (!IsValidFileName(filename))
		return false;

	// opens file pointer with filename
	// checks if it has been successfully opened
	FILE* fp;
	if (!(fp = fopen(filename, "rb")))
		return false;

	// allocate memory for tournament being loaded
	*tournamentSize = ARR_START_SIZE;
	if (!(savedTournament = (PARTICIPANT*)malloc(*tournamentSize * sizeof(PARTICIPANT))))
		return false;
	strcpy(savedTournament, "");
	
	// allocate memory to temporarily store incoming participants
	PARTICIPANT* p;
	if (!(p = (PARTICIPANT*)malloc(sizeof(PARTICIPANT))))
		return false;

	// reads saved file until there is nothing left to read
	for (int i = 0; fread(p, sizeof(PARTICIPANT), 1, fp) == 1; i++) {
		// resizes and copies the tournament if the current size is too small;
		if (i > *tournamentSize) {
			PARTICIPANT* tempTournament = savedTournament;
			int oldSize = *tournamentSize;
			*tournamentSize *= 2;
			savedTournament = (PARTICIPANT*)realloc(savedTournament, sizeof(PARTICIPANT) * *tournamentSize);
			if (!savedTournament)
				return false;
			for (int j = 0; j < oldSize; j++)
				savedTournament[j] = tempTournament[j];
			free(tempTournament);
		}
		// populates tournament with participant data being loaded
		savedTournament[i] = *p;
	}

	// frees temporary participant
	// and closes file pointer
	free(p);
	fclose(fp);

	// returns true if load was successful
	return true;
}

// checks if filename is valid for saving
// returns false if it is not
bool IsValidFileName(char filename[]) {
	// array of invalid file characters
	char illegalCharacters[] = { '#', '%', '&', '{', '}', '\\', '<', '>', '*', '?', '/', ' ',
								'$', '!', '\'', '\"', ':', '@', '+', '`', '|', '=', '\0'};
	// loops through file name checking if each character is valid or not
	for (int i = 0; i < strlen(filename); i++) {
		for (int j = 0; j < strlen(illegalCharacters); j++)
			if (filename[i] == illegalCharacters[j])
				return false;
	}

	return true;
}