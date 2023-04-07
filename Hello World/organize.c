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
	printf("-----------------------------------\n");
	for (int i = 0; i < num; i++) {
		printf("ID: %d, Name: %s\n", participants[i].id, participants[i].name);
	}
	printf("-----------------------------------\n");
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



void random(PARTICIPANT * participants, int num)										//Random Function
{
	srand(time(NULL));																	//Use Random number generator

	for (int i = 0; i < num; i++) {
		participants[i].id = rand() % (num * 10) + 1;									//Use number from 1-10
	}
}


void mannual(PARTICIPANT* participants, int num)
{
	int* assigned_ids = calloc(num, sizeof(int));
	int id;
	int input_count;

	for (int i = 0; i < num; i++) {
		printf("\nEnter Number for name %s: ", participants[i].name);
		input_count = scanf("%d", &id);
		while (input_count != 1) {
			printf("\nInvalid entry, try again");
			while (getchar() != '\n');  // clear input buffer
			input_count = scanf("%d", &id);
		}
		bool id_assigned = false;
		for (int j = 0; j < i; j++) {
			if (assigned_ids[j] == id) {
				printf("\nNumber already assigned to another name, try again");
				i--;
				id_assigned = true;
				break;
			}
		}
		if (!id_assigned) {
			participants[i].id = id;
			assigned_ids[i] = id;
		}
	}
	free(assigned_ids);
}