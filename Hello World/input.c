#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAMESIZE 10

typedef struct participant {
	char name[MAXNAMESIZE];
	int id;
}PARTICIPANT;

int main(void) {

	int numOfParticipants;

	printf("Enter Num: ");
	if (scanf("%d", &numOfParticipants) != 1) {
		printf("\nInlavid Entry");
		exit(1);
	}

	PARTICIPANT* participant = (PARTICIPANT*)malloc(sizeof(PARTICIPANT) * numOfParticipants);
	for (int i = 0; i < numOfParticipants; i++) {
		printf("\nEnter the name for partipant %d: ", i + 1);
		if (scanf("%s", participant[i].name) != 1) {
			printf("\nInvalid Entry, try again");
			i--;
		}
	}

	free(participant);

	return 0;
}