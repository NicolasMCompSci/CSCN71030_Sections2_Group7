#include "numInput.h"

#define CASE1 2
#define CASE2 4
#define CASE3 8
#define CASE4 16
#define CASE5 32
#define CASE6 64

int integerInput() {
	int numOfParticipants = 0;
	printf("Enter the size of the tournament: ");
	if (scanf("%d", &numOfParticipants) != 1) {
		printf("\nInlavid Entry");
		exit(1);
	}
	return numOfParticipants;
}

int sizeOfTournament(int numOfParticipants, bool choice) {
	int newNum = 0;
		if (numOfParticipants < CASE1) {
			newNum = CASE1;
		}
		else if (numOfParticipants < CASE2) {
			newNum = CASE2;
		}
		else if (numOfParticipants < CASE3) {
			newNum = CASE3;
		}
		else if (numOfParticipants < CASE4) {
			newNum = CASE4;
		}
		else if (numOfParticipants < CASE5) {
			newNum = CASE5;
		}
		else if (numOfParticipants < CASE6) {
			newNum = CASE6;
		}
		else {
			newNum = CASE6;
		}
		if (choice == true) {
			numOfParticipants = newNum;
		}
		else {
			printf("\nWrong choice buckoo");
			exit(1);
		}
	return numOfParticipants;
}

bool willNumChange() {
	char willUserChangeNum[MAXNAMESIZE] = "";
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