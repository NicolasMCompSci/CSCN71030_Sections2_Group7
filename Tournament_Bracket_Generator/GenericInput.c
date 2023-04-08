// CSCN71030 - winter 2023
// Group Project - Tournament Bracket Generator
// Nicolas Masquieto, Ethan Groen, Louis He
// 
// Implementation for some generic input functions

#define _CRT_SECURE_NO_WARNINGS
#define STRING_START_SIZE 100

#include "GenericInput.h"
#include <stdlib.h>
#include <stdio.h>

// return integer user input that 
int getWholeNumAsInt() {
	// variable that will hold user input temporarily, initialized to 0 for safety
	int tempInput = 0;

	//take user input and validates it, and checks if it is a natural number
	if (scanf("%d", &tempInput) != 1 || tempInput < 0){
		// clears anything remaining in the input
		ClearSTDIn();
		// print error message and retry to get the input.
		printf("invalid input. Number must be equal to or greater than 0.\n");
		tempInput = getWholeNumAsInt();
	}

	// returns input
	return tempInput;
}

// Clears stdin from any input still hanging there
void ClearSTDIn() {
	// while not at the end of stdin keep dumping the input
	char dump;
	while ((dump = getchar()) != '\n' && dump != EOF);
}

// returns a string user input
char* getString() {
	// minimum string size set to 100
	size_t stringCapacity = STRING_START_SIZE;
	// allocate memory for input
	char* input = (char*)malloc(sizeof(*input) * stringCapacity);
	if (!input) {
		printf("Error allocating memory to input");
		return NULL;
	}

	// declare char variable for individual letters and index variable to count
	char ch;
	size_t currIndex = 0;

	// gets input from stdin char by char, increasing size and alloc of string every time
	while ((ch = getc(stdin)) != '\n' && ch != EOF) {

		input[currIndex++] = ch;
		// if string is full, allocate more memory
		if (currIndex == stringCapacity) {

			char* buffer = (char*)realloc(input, sizeof(char) * (stringCapacity += STRING_START_SIZE));
			if (!buffer) {
				printf("Error allocating memory to input");
				return NULL;
			}
			else
				input = buffer;
		}
	}

	// if string is full, allocate more memory
	if (currIndex == stringCapacity) {

		char* buffer = (char*)realloc(input, sizeof(char) * (stringCapacity += STRING_START_SIZE));
		if (!buffer) {
			printf("Error allocating memory to input");
			return NULL;
		}
		else
			input = buffer;
	}
	// add null terminator
	if (input != NULL)
		input[currIndex++] = '\0';

	// reallocate memory for the final input
	char* buffer = (char*)realloc(input, sizeof(char) * currIndex);
	if (!buffer) {
		printf("Error allocating memory to input");
		return NULL;
	}
	else
		input = buffer;

	// returns string
	return input;
}