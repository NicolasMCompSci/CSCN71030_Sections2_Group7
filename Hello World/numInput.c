#include "numInput.h"

#define CASE1 2
#define CASE2 4
#define CASE3 8
#define CASE4 16
#define CASE5 32
#define CASE6 64

int sizeOfTournament() {
	int numOfParticipants = 0;
	int newNum = 0;
	printf("Enter Num: ");
	if (scanf("%d", &numOfParticipants) != 1) {
		printf("\nInlavid Entry");
		exit(1);
	}
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
		printf("\nThe tournament size that works best for your inputted number is %d, would you like to change the size to %d? (yes or no) \n", newNum, newNum);
		if (willNumChange() == true) {
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