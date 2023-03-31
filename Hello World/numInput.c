#include "numInput.h"

int sizeOfTournament() {
	int numOfParticipants = 0;

	printf("Enter Num: ");
	if (scanf("%d", &numOfParticipants) != 1) {
		printf("\nInlavid Entry");
		exit(1);
	}
	if (numOfParticipants < 4) {
		printf("\nThe tournament size that works best for your inputted number is 4, would you like to change the size to 4? (yes or no) \n");
		if (willNumChange() == true) {
			numOfParticipants = 4;
		}
		else {
			printf("\nWrong choice buckoo");
			exit(1);
		}
	}
	return numOfParticipants;
}

bool willNumChange() {
	char willUserChangeNum[MAXNAMESIZE];
	if (scanf("%s", willUserChangeNum) != 1) {
		printf("Invalid input");
		exit(1);
	}
	if (strcmp(willUserChangeNum, "yes") == 0) {
		return true;
	}
	else {
		return false;
	}
}