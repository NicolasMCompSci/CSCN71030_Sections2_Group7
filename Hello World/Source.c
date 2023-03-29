// CSCN71030 - winter 2023
// Group Project - Tournament Bracket Generator
// Nicolas Masquieto, Ethan Groen, Louis He

// This is a simple "Hello World" program as per the GitHub setup requirements

#define _CRT_SECURE_NO_WARNINGS
#include "Participant.h"
#include"Display.h"
#include<string.h>
#include <stdio.h>

int main(void) {
	PARTICIPANT p[4];
	p[0].id = 2, strcpy(p[0].name, "p0");
	p[1].id = 1, strcpy(p[1].name, "p1");
	p[2].id = 4, strcpy(p[2].name, "p2");
	p[3].id = 3, strcpy(p[3].name, "p3");

	DisplayTournament_Short(p, 4);
	DisplayTournament_Full(p, 4);
}