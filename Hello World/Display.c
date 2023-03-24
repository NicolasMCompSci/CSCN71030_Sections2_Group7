// CSCN71030 - winter 2023
// Author: Nicolas Masquieto
// 
// Implementation for display functions

#include "Display.h"
#include <stdio.h>
#include <stdarg.h>

// Displays a menu of variable size according to optionCount.
// Every new option prompt is another line.
void PrintMenu(int optionCount, char option[], ...)
{
	va_list valist;
	// allocate memory and inilialize list
	va_start(valist, option);

	// iterates through optionCount number of arguments
	// optionCount is subtracted by one to turn it into an index
	printf("%s\n", option);
	for (int i = 0; i < optionCount - 1; i++)
		printf("%s\n", va_arg(valist, char*));

	// clean memory reserved for list
	va_end(valist);
}