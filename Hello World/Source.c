#define _CRT_SECURE_NO_WARNINGS

#include "participant.h"
#include "nameInput.h"
#include "numInput.h"
#include "FileIO.h"
#include "Display.h"
#include "organize.h"
#include <stdbool.h>


int main(int argc, char* argv[]) {

	PARTICIPANT* tournament;
	if (argc > 2)
		tournament = Load(argv[0]);

	bool continueProgram = true;
	while(continueProgram) {

		DisplayMenu(7, "\nWhat do you want to do?\n",
						"1. New Tournament",
						"2. Edit current Tournament",
						"3. Display compact bracket",
						"4. Display graph form bracket",
						"5. Save",
						"6. Load",
						"7. Quit");

		int tournamentSize = sizeOfTournament();
		tournament = (PARTICIPANT*)malloc(sizeof(PARTICIPANT) * tournamentSize);
		assignNames(tournament, tournamentSize);
	}

	free(tournament);
	return 0;
}