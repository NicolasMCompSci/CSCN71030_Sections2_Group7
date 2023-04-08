// CSCN71030 - winter 2023
// Author: Nicolas Masquieto
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