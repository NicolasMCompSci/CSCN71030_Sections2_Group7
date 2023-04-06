#define _CRT_SECURE_NO_WARNINGS

#include "participant.h"
#include "FileIO.h"
#include "GenericInput.h"
#include "numInput.h"
#include "nameInput.h"
#include "organize.h"
#include "Display.h"
#include <stdbool.h>

int main(int argc, char* argv[]) {

	PARTICIPANT* tournament = NULL;
	int tempInt = 0;
	int tournamentSize = 0;
	if (argc > 2)
		if (!Load(tournament, &tournamentSize, argv[0]))
			printf("Failed to load file from command line.\n");
		else
			printf("File loaded from command line argument.\n");

	bool continueProgram = true;
	while(continueProgram) {

		// Displays option menu to user
		DisplayMenu(8, "\nWhat do you want to do?\n",
						"1. New Tournament",
						"2. Edit current Tournament",
						"3. Display compact bracket",
						"4. Display graph form bracket",
						"5. Save",
						"6. Load",
						"0. Quit");

		// get menu input and initialize filename string
		int menuInput = getWholeNumAsInt();
		char* fileName = NULL;
		// menu logic
		switch (menuInput) {
		case 1:
			// --------------
			// NEW TOURNAMENT
			// --------------
			
			// get new tournament size
			tempInt = integerInput();
			if ((tempInt != 0) && ((tempInt & (tempInt - 1)) == 0)) {
				tournamentSize = tempInt;
			}
			else {
				printf("\nThe tournament size that you entered is invalid would you like to switch to the closest (but higher) value (yes or no) \n");
				bool choice = willNumChange();
				tournamentSize - sizeOfTournament(tempInt, choice);
			}
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
			// ------------
			// ORGANIZATION
			// ------------

			// calls organization submenu
			OrganizeMenu(tournament, tournamentSize);
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
			// gets name input from user
			fileName = getString();
			// updates filename with user input
			strcpy(fileName, getString());
			// saves tournament to file.
			// Also checks if save was successful, if not then print error message
			if (!Save(tournament, tournamentSize, fileName))
				printf("An error occurred. Try again.\n");
			else
				printf("Your file has been saved successfully.\n");
			break;
		case 6:
			// ----
			// LOAD
			// ----

			// asks user for name of file being loaded
			printf("Input a name for the file being loaded: ");
			// gets name input from user
			fileName = getString();
			// updates filename with user input
			strcpy(fileName, getString());
			// loads tournament and tournament size from file
			// also prints error message on allocation error or not finding file
			if (!Load(&tournament, &tournamentSize, fileName))
				printf("An error occurred. Try again.\n");
			else
				printf("Your file has been loaded successfully.\n");
			break;
		case 0:
			// ----
			// QUIT
			// ----

			// breaks out of while loop and ends program
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