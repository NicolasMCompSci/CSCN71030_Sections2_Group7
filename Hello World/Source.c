#define _CRT_SECURE_NO_WARNINGS

#include "nameInput.h"
#include "numInput.h"
#include "participant.h"

int main(void) {

	int tournamentSize = sizeOfTournament();

	PARTICIPANT* participant = (PARTICIPANT*)malloc(sizeof(PARTICIPANT) * tournamentSize);
	assignNames(participant, tournamentSize);

	free(participant);
	return 0;
}