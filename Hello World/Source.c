#define _CRT_SECURE_NO_WARNINGS

#include "participant.h"
#include "nameInput.h"
#include "numInput.h"
#include "FileIO.h"
#include "Display.h"
#include "organize.h"
#include <stdbool.h>

#define MAX_FILE_NAME 200

int main(int argc, char* argv[]) {

	PARTICIPANT* tournament = NULL;
	int tournamentSize = 0;
	if (argc > 2)
		if (!Load(tournament, &tournamentSize, argv[0]))
			printf("Failed to load file from command line.\n");
		else
			printf("File loaded from command line argument.\n");

	bool continueProgram = true;
	while(continueProgram) {

		// Displays option menu to user
		DisplayMenu(7, "\nWhat do you want to do?\n",
						"1. New Tournament",
						"2. Edit current Tournament",
						"3. Display compact bracket",
						"4. Display graph form bracket",
						"5. Save",
						"6. Load",
						"0. Quit");

		// get menu input and initialize filename string
		int menuInput = getInt();
		char fileName[MAX_FILE_NAME];
		// menu logic
		switch (menuInput) {
		case 1:
			// --------------
			// NEW TOURNAMENT
			// --------------
			
			// get new tournament size
			tournamentSize = sizeOfTournament();
			// if already allocated, clear allocation for new tournament
			if (tournament)
				free(tournament);
			// allocate new memory for tournament
			tournament = (PARTICIPANT*)malloc(sizeof(PARTICIPANT) * tournamentSize);
			if (!tournament) {
				printf("memory allocation for new tournament failed.");
				exit(2);
			}
			// assign names to tournament
			assignNames(tournament, tournamentSize);
			break;
		case 2:

			// add organize functionality here

			break;
		case 3:
			// ---------------
			// DISPLAY COMPACT
			// ---------------

			// Displays compact matches
			DisplayTournament_Short(tournament, tournamentSize);
			break;
		case 4:
			// -------------
			// DISPLAY GRAPH
			// -------------
			
			// Displays full tournament graph
			DisplayTournament_Full(tournament, tournamentSize);
			break;
		case 5:
			// ----
			// SAVE
			// ----
			
			// asks user for name of file being saved
			printf("Input a name for the file being saved: ");
			// updates filename with user input
			strcpy(fileName, getString());
			// saves tournament to file.
			// Also checks if save was successful, if not then print error message
			if (!Save(tournament, tournamentSize, fileName))
				printf("Saving failed.\n File name invalid or allocation error.\n Check if your drive has enough space left.\n"
					"Also remember to not use any of the following characters for the file name:\n #, %, &, {, }, \\,"
					"<, >, *, ?, /, ' ', $, !, \', \", :, @, +, `, |, or =\n");
			else
				printf("Your file has been saved successfully.\n");
			break;
		case 6:
			// ----
			// LOAD
			// ----
			// asks user for name of file being loaded
			printf("Input a name for the file being loaded: ");
			// updates filename with user input
			strcpy(fileName, getString());
			// loads tournament and tournament size from file
			// also prints error message on allocation error or not finding file
			if (!Load(tournament, &tournamentSize, fileName))
				printf("Load failed.\n File name invalid or allocation error.\n Check if your drive has enough space left.\n"
					"Also remember to not use any of the following characters for the file name:\n #, %, &, {, }, \\,"
					"<, >, *, ?, /, ' ', $, !, \', \", :, @, +, `, |, or =\n");
			else
				printf("Your file has been loaded successfully.\n");
			break;
		case 0:
			// ----
			// QUIT
			// ----
			continueProgram = false;
			break;
		default:
			printf("That's not a valid input.\n");
			break;
		}
	}

	free(tournament);
	return 0;
}