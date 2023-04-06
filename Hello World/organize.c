#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


#include "organize.h"
#include "GenericInput.h"


void printParticipants(PARTICIPANT* participants, int num)						// Display Tournament
{
	printf("List of Participants:\n");
	printf("----------------\n");
	for (int i = 0; i < num; i++) {
		printf("ID: %d, Name: %s\n", participants[i].id, participants[i].name);
	}
	printf("----------------\n");
}


void OrganizeMenu(PARTICIPANT* participants, int num)										//Tournament Organization Menu
{
	printf("------ Tournament Organization Sub-Menu ------\n");							
	printf("\n 1. Assign IDs randomly\n 2. Assign IDs manually\n 0. Quit\n");
	printf("Enter a number here: \n");
	int Option = getWholeNumAsInt();

	bool continueInMenu = true;
	while (continueInMenu) {
		if (Option == 1) {																	//Swtich to Random function
			random(participants, num);
			continueInMenu = false;
		}
		else if (Option == 2) {																//Swtich to Mannual function
			mannual(participants, num);
			continueInMenu = false;
		}
		else if (Option == 0)
			return;
		else																				//If A wrong choice
			printf("\nInvalid entry.\n");
	}

	printParticipants(participants, num);
}

// archived, since it is no longer used.
//void assign(PARTICIPANT* participants, int num)											//Assign to different group
//{
//	for (int i = 0; i < num; i++) {														// Calculate the number on the name
//		int num = 0;
//		for (int j = 0; j < strlen(participants[i].name); j++) {
//			num += participants[i].name[j];
//		}
//		participants[i].group_id = num % 4 + 1;											// Move it to group
//	}
//}	

void random(PARTICIPANT * participants, int num)										//Random Function
{
	srand(time(NULL));																	//Use Random number generator

	for (int i = 0; i < num; i++) {
		participants[i].id = rand() % (num * 10) + 1;									//Use number from 1-10
	}
}

void mannual(PARTICIPANT * participants, int num)										//Mannual Function
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

