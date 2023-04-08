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

void random(PARTICIPANT * participants, int num)										//Random Function
{
	srand(time(NULL));																	//Use Random number generator

	for (int i = 0; i < num; i++) {
		participants[i].id = rand() % (num * 10) + 1;									//Use number from 1-10
	}
}

void mannual(PARTICIPANT* participants, int num) {
	for (int i = 0; i < num; i++) {
		printf("Enter number for participant %s: ", participants[i].name);
		int number;
		scanf("%d", &number);

		if (number <= 0) {
			printf("Error: Invalid number entered.\n");
			i--;
			continue;
		}

		int number_used = 0;
		int name_used = 0;
		for (int j = 0; j < num; j++) {
			if (j == i) continue;
			if (participants[j].id == number) {
				number_used = 1;
				break;
			}
			if (strcmp(participants[j].name, participants[i].name) == 0) {
				name_used = 1;
				break;
			}
		}
		if (number_used) {
			printf("Error: Number already used.\n");
			i--;
		}
		else if (name_used) {
			printf("Error: Name already used.\n");
			i--;
		}
		else {
			participants[i].id = number;
		}
	}
}

void mannualTest(PARTICIPANT* participants, int num, int* numbers)					//Same like my Mannual Function but it will not ask for user input
{
for (int i = 0; i < num; i++) {
		int number = numbers[i];

		if (number <= 0) {
			printf("Error: Invalid number entered.\n");
			continue;
		}

		int number_used = 0;
		int name_used = 0;
		for (int j = 0; j < num; j++) {
			if (j == i) continue;
			if (participants[j].id == number) {
				number_used = 1;
				break;
			}
			if (strcmp(participants[j].name, participants[i].name) == 0) {
				name_used = 1;
				break;
			}
		}
		if (number_used) {
			printf("Error: Number already used.\n");
		}
		else if (name_used) {
			printf("Error: Name already used.\n");
		}
		else {
			participants[i].id = number;
		}
	}
}