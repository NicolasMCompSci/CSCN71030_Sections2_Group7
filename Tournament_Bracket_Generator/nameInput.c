#include "numInput.h"
#include "participant.h"
#include "nameInput.h"

void assignNames(PARTICIPANT* p, int size) {
	for (int i = 0; i < size; i++) {
		printf("\nEnter the name for partipant %d: ", i + 1);
		if (scanf("%s", p[i].name) != 1) { 
			printf("\nInvalid Entry, try again");
			i--;
			continue;
		}
	}
}