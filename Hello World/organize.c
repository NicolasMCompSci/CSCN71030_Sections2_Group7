#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "organize.h"


void printmenu(PARTICIPANT* participants, int num)									//Tournament Organization Menu
{
	int assignOption;
	printf("------ Tournament Organization Menu ------\n");							
	printf("\n 1. Assign IDs randomly\n 2. Assign IDs manually\n");
	printf("Enter a number here: \n");
	if (scanf("%d", &assignOption) != 1) {
		printf("\nInvalid entry.\n");
		exit(1);
	}

	if (assignOption == 1) {													//Swtich to Random function
		random(participants, num);
	}
	else if (assignOption == 2) {												//Swtich to Mannual function
		mannual(participants, num);
	}
	else {																		//If A wrong choice
		printf("\nInvalid entry.\n");
		exit(1);
	}

	printParticipants(participants, num);

	free(participants);
	return 0;

}



void random(PARTICIPANT* participants, int num)							//Random Function
{
	srand(time(NULL));													//Use Random number generator

	for (int i = 0; i < num; i++) {
		participants[i].id = rand() % 10+1;								//Use number from 1-10
	}
}

void mannual(PARTICIPANT* participants, int num)										//Mannual Function
{
	int id;

	for (int i = 0; i < num; i++) {
		printf("\nEnter Number for name %s: ", participants[i].name);					//Ask number for a name
		if (scanf("%d", &id) != 1) {
			printf("\nInvalid entry, try again");										//if Wrong number 
			i--;
			continue;
		}
		for (int j = 0; j < i; j++) {													//If this number already assigned for a name
			if (participants[j].id == id) {
				printf("\nNumber already assigned to another name, try again");
				i--;
				continue;
			}
		}
		participants[i].id = id;
	}

}

