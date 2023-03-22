// PROG72365 - winter 2023
// Nicolas Masquieto
// 
// Assignment 01
// 
// Error message implementation

#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <stdio.h>
#include <stdlib.h>

// displays an error message that was passed as a parameter,
// and exits with a failure
void Print_Exit(char message[]) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}