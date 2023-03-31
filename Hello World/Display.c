// CSCN71030 - winter 2023
// Author: Nicolas Masquieto
// 
// Implementation for display functions

#include "Display.h"
#include <stdio.h>
#include <stdarg.h>

#define LINE_NAME_SIZE MAXNAMESIZE+2
#define INNERLINE_NAME_SIZE LINE_NAME_SIZE+2

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

// Displays the tournment bracket.
void DisplayTournament_Short(PARTICIPANT tournament[], size_t participantCount) {
	// loops through the array, incrementing the player count by 2 every iteration
	// as 2 players are printed at the same time.
	for (int player = 0, round = 1; player < participantCount; player+=2, round++)
		printf("Match %d: %s vs %s\n", round, tournament[SearchArrayIndexFromID(tournament, participantCount, player+1)].name,
				tournament[SearchArrayIndexFromID(tournament, participantCount, player+2)].name);
	printf("\n");
}

void DisplayTournament_Full(PARTICIPANT tournament[], size_t participantCount) {
	// intialize starting id to 0 before counting
	int id = 0;

	// prints brackets dependant on tournament size
	switch (participantCount) {
	case 2:
		printf("%d - %10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		printf("%14s\\\n", " ");
		printf("%14s ----------\n", " ");
		printf("%14s/\n", " ");
		printf("%d - %10s\n\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		break;
	case 4:
		printf("%d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		printf("%14s\\\n", " ");
		printf("%14s ----------\n", " ");
		printf("%14s/%10s\\\n", " ", " ");
		printf("%d - %-10s%12s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%26s ----------\n", " ");
		printf("%d - %-10s%12s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%14s\\%10s/\n", " ", " ");
		printf("%14s ----------\n", " ");
		printf("%14s/\n", " ");
		printf("%d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		break;
	case 8:
		printf("%d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		printf("%14s\\\n", " ");
		printf("%14s ----------\n", " ");
		printf("%14s/%10s\\\n", " ", " ");
		printf("%d - %-10s%12s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%26s ----------\n", " ");
		printf("%d - %-10s%12s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%14s\\%10s/%12s\\\n", " ", " ", " ");
		printf("%14s ----------%14s\\\n", " ", " ");
		printf("%14s/%25s\\\n", " ", " ");
		printf("%d - %-10s%27s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%41s ----------\n", " ");
		printf("%d - %-10s%27s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%14s\\%25s/\n", " ", " ");
		printf("%14s ----------%14s/\n", " ", " ");
		printf("%14s/%10s\\%12s/\n", " ", " ", " ");
		printf("%d - %-10s%12s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%26s ----------\n", " ");
		printf("%d - %-10s%12s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%14s\\%10s/\n", " ", " ");
		printf("%14s ----------\n", " ");
		printf("%14s/\n", " ");
		printf("%d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		break;
	case 16:
		printf("%2d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		printf("%15s\\\n", " ");
		printf("%15s ----------\n", " ");
		printf("%15s/%10s\\\n", " ", " ");
		printf("%2d - %-10s%12s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%27s ----------\n", " ");
		printf("%2d - %-10s%12s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%14s\\\n", " ", " ");
		printf("%15s/%25s\\\n", " ", " ");
		printf("%2d - %-10s%27s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%42s ----------\n", " ");
		printf("%2d - %-10s%27s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%25s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%20s\\\n", " ", " ");
		printf("%2d - %-10s%12s/%31s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%33s\\\n", " ", " ", " ");
		printf("%15s ----------%35s\\\n", " ", " ");
		printf("%15s/%46s\\\n", " ", " ");
		printf("%2d - %-10s%48s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%63s ----------\n", " ");
		printf("%2d - %-10s%48s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%46s/\n", " ", " ");
		printf("%15s ----------%35s/\n", " ", " ");
		printf("%15s/%10s\\%33s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------%20s/\n", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/\n", " ", " ", " ");
		printf("%15s/%25s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%42s ----------\n", " ");
		printf("%2d - %-10s%27s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%25s/\n", " ", " ");
		printf("%15s ----------%14s/\n", " ", " ");
		printf("%15s/%10s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------\n", " ");
		printf("%2d - %-10s%12s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%10s/\n", " ", " ");
		printf("%15s ----------\n", " ");
		printf("%15s/\n", " ");
		printf("%2d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		break;
	case 32:
		printf("%2d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		printf("%15s\\\n", " ");
		printf("%15s ----------\n", " ");
		printf("%15s/%10s\\\n", " ", " ");
		printf("%2d - %-10s%12s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%27s ----------\n", " ");
		printf("%2d - %-10s%12s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%14s\\\n", " ", " ");
		printf("%15s/%25s\\\n", " ", " ");
		printf("%2d - %-10s%27s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%42s ----------\n", " ");
		printf("%2d - %-10s%27s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%25s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%20s\\\n", " ", " ");
		printf("%2d - %-10s%12s/%31s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%33s\\\n", " ", " ", " ");
		printf("%15s ----------%35s\\\n", " ", " ");
		printf("%15s/%46s\\\n", " ", " ");
		printf("%2d - %-10s%48s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%63s ----------\n", " ");
		printf("%2d - %-10s%48s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%46s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%35s/%14s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%33s/%16s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/%18s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%20s/%20s\\\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/%22s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/%24s\\\n", " ", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/%26s\\\n", " ", " ", " ", " ");
		printf("%15s/%25s\\%12s/%28s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/%30s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%42s ----------%32s\\\n", " ", " ");
		printf("%2d - %-10s%27s/%43s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%25s/%45s\\\n", " ", " ", " ");
		printf("%15s ----------%14s/%47s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%12s/%49s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%51s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%53s\\\n", " ", " ");
		printf("%2d - %-10s%12s/%64s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%66s\\\n", " ", " ", " ");
		printf("%15s ----------%68s\\\n", " ", " ");
		printf("%15s/%79s\\\n", " ", " ");
		printf("%2d - %-10s%81s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%96s ----------\n", " ");
		printf("%2d - %-10s%81s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%79s/\n", " ", " ");
		printf("%15s ----------%68s/\n", " ", " ");
		printf("%15s/%10s\\%66s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%64s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------%53s/\n", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%51s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%12s\\%49s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%47s/\n", " ", " ", " ");
		printf("%15s/%25s\\%45s/\n", " ", " ", " ");
		printf("%2d - %-10s%27s\\%43s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%42s ----------%32s/\n", " ", " ");
		printf("%2d - %-10s%27s/%10s\\%30s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%25s/%12s\\%28s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\%26s/\n", " ", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\%24s/\n", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\%22s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%27s ----------%20s\\%20s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%31s\\%18s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%33s\\%16s/\n", " ", " ", " ", " ");
		printf("%15s ----------%35s\\%14s/\n", " ", " ", " ");
		printf("%15s/%46s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%48s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%63s ----------\n", " ");
		printf("%2d - %-10s%48s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%46s/\n", " ", " ");
		printf("%15s ----------%35s/\n", " ", " ");
		printf("%15s/%10s\\%33s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------%20s/\n", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/\n", " ", " ", " ");
		printf("%15s/%25s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%42s ----------\n", " ");
		printf("%2d - %-10s%27s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%25s/\n", " ", " ");
		printf("%15s ----------%14s/\n", " ", " ");
		printf("%15s/%10s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------\n", " ");
		printf("%2d - %-10s%12s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%10s/\n", " ", " ");
		printf("%15s ----------\n", " ");
		printf("%15s/\n", " ");
		printf("%2d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		break;
	case 64:
		printf("%2d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		printf("%15s\\\n", " ");
		printf("%15s ----------\n", " ");
		printf("%15s/%10s\\\n", " ", " ");
		printf("%2d - %-10s%12s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%27s ----------\n", " ");
		printf("%2d - %-10s%12s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%14s\\\n", " ", " ");
		printf("%15s/%25s\\\n", " ", " ");
		printf("%2d - %-10s%27s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%42s ----------\n", " ");
		printf("%2d - %-10s%27s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%25s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%20s\\\n", " ", " ");
		printf("%2d - %-10s%12s/%31s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%33s\\\n", " ", " ", " ");
		printf("%15s ----------%35s\\\n", " ", " ");
		printf("%15s/%46s\\\n", " ", " ");
		printf("%2d - %-10s%48s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%63s ----------\n", " ");
		printf("%2d - %-10s%48s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%46s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%35s/%14s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%33s/%16s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/%18s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%20s/%20s\\\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/%22s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/%24s\\\n", " ", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/%26s\\\n", " ", " ", " ", " ");
		printf("%15s/%25s\\%12s/%28s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/%30s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%42s ----------%32s\\\n", " ", " ");
		printf("%2d - %-10s%27s/%43s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%25s/%45s\\\n", " ", " ", " ");
		printf("%15s ----------%14s/%47s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%12s/%49s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%51s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%53s\\\n", " ", " ");
		printf("%2d - %-10s%12s/%64s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%66s\\\n", " ", " ", " ");
		printf("%15s ----------%68s\\\n", " ", " ");
		printf("%15s/%79s\\\n", " ", " ");
		printf("%2d - %-10s%81s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%96s ----------\n", " ");
		printf("%2d - %-10s%81s/%10s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%79s/%12s\\\n", " ", " ", " ");
		printf("%15s ----------%68s/%14s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%66s/%16s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%64s/%18s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%53s/%20s\\\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%51s/%22s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%15s\\%10s/%12s\\%49s/%24s\\\n", " ", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%47s/%26s\\\n", " ", " ", " ", " ");
		printf("%15s/%25s\\%45s/%28s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%27s\\%43s/%30s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%42s ----------%32s/%32s\\\n", " ", " ", " ");
		printf("%2d - %-10s%27s/%10s\\%30s/%34s\\ \n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%15s\\%25s/%12s\\%28s/%36s\\\n", " ", " ", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\%26s/%38s\\\n", " ", " ", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\%24s/%40s\\\n", " ", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\%22s/%42s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ", " ");
		printf("%27s ----------%20s\\%20s/%44s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s/%31s\\%18s/%46s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%15s\\%10s/%33s\\%16s/%48s\\\n", " ", " ", " ", " ", " ");
		printf("%15s ----------%35s\\%14s/%50s\\\n", " ", " ", " ", " ");
		printf("%15s/%46s\\%12s/%52s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%48s\\%10s/%54s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%63s ----------%56s\\\n", " ", " ");
		printf("%2d - %-10s%48s/%67s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%46s/%69s\\\n", " ", " ", " ");
		printf("%15s ----------%35s/%71s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%33s/%73s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/%75s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%20s/%77s\\\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/%79s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/%81s\\\n", " ", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/%83s\\\n", " ", " ", " ", " ");
		printf("%15s/%25s\\%12s/%85s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/%87s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%42s ----------%89s\\\n", " ", " ");
		printf("%2d - %-10s%27s/%100s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%25s/%102s\\\n", " ", " ", " ");
		printf("%15s ----------%14s/%104s\\\n", " ", " ", " ");
		printf("%15s/%10s\\%12s/%106s\\\n", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%108s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%27s ----------%110s\\\n", " ", " ");
		printf("%2d - %-10s%12s/%121s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%15s\\%10s/%123s\\\n", " ", " ", " ");
		printf("%15s ----------%125s\\\n", " ", " ");
		printf("%15s/%136s\\\n", " ", " ");
		printf("%2d - %-10s%138s\\\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%153s ----------\n", " ");
		printf("%2d - %-10s%138s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%136s/\n", " ", " ");
		printf("%15s ----------%125s/\n", " ", " ");
		printf("%15s/%10s\\%123s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%121s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------%110s/\n", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%108s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%12s\\%106s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%104s/\n", " ", " ", " ");
		printf("%15s/%25s\\%102s/\n", " ", " ", " ");
		printf("%2d - %-10s%27s\\%100s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%42s ----------%89s/\n", " ", " ");
		printf("%2d - %-10s%27s/%10s\\%87s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%25s/%12s\\%85s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\%83s/\n", " ", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\%81s/\n", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\%79s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%27s ----------%20s\\%77s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%31s\\%75s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%33s\\%73s/\n", " ", " ", " ", " ");
		printf("%15s ----------%35s\\%71s/\n", " ", " ", " ");
		printf("%15s/%46s\\%69s/\n", " ", " ", " ");
		printf("%2d - %-10s%48s\\%67s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%63s ----------%56s/\n", " ", " ");
		printf("%2d - %-10s%48s/%10s\\%54s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%46s/%12s\\%52s/\n", " ", " ", " ", " ");
		printf("%15s ----------%35s/%14s\\%50s/\n", " ", " ", " ", " ");
		printf("%15s/%10s\\%33s/%16s\\%48s/\n", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/%18s\\%46s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%27s ----------%20s/%20s\\%44s/\n", "", " ", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/%22s\\%42s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/%24s\\%40s/\n", " ", " ", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/%26s\\%38s/\n", " ", " ", " ", " ", " ");
		printf("%15s/%25s\\%12s/%28s\\%36s/\n", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/%30s\\%34s/ \n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%42s ----------%32s\\%32s/ \n", " ", " ", " ");
		printf("%2d - %-10s%27s/%42s \\ %29s/ \n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%25s/%45s\\%28s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s/%47s\\%26s/\n", " ", " ", " ", " ");
		printf("%15s/%10s\\%12s/%49s\\%24s/\n", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%51s\\%22s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%27s ----------%53s\\%20s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%64s\\%18s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%66s\\%16s/\n", " ", " ", " ", " ");
		printf("%15s ----------%68s\\%14s/\n", " ", " ", " ");
		printf("%15s/%79s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%81s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%96s ----------\n", " ");
		printf("%2d - %-10s%81s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%79s/\n", " ", " ");
		printf("%15s ----------%68s/\n", " ", " ");
		printf("%15s/%10s\\%66s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%64s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------%53s/\n", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%51s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%12s\\%49s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%47s/\n", " ", " ", " ");
		printf("%15s/%25s\\%45s/\n", " ", " ", " ");
		printf("%2d - %-10s%27s\\%43s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%42s ----------%32s/\n", " ", " ");
		printf("%2d - %-10s%27s/%10s\\%30s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%25s/%12s\\%28s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s/%14s\\%26s/\n", " ", " ", " ", " ");
		printf("%15s/%10s\\%12s/%16s\\%24s/\n", " ", " ", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/%18s\\%22s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ", " ");
		printf("%27s ----------%20s\\%20s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s/%31s\\%18s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%33s\\%16s/\n", " ", " ", " ", " ");
		printf("%15s ----------%35s\\%14s/\n", " ", " ", " ");
		printf("%15s/%46s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%48s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%63s ----------\n", " ");
		printf("%2d - %-10s%48s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%46s/\n", " ", " ");
		printf("%15s ----------%35s/\n", " ", " ");
		printf("%15s/%10s\\%33s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%31s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------%20s/\n", " ", " ");
		printf("%2d - %-10s%12s/%10s\\%18s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ", " ");
		printf("%15s\\%10s/%12s\\%16s/\n", " ", " ", " ", " ");
		printf("%15s ----------%14s\\%14s/\n", " ", " ", " ");
		printf("%15s/%25s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%27s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%42s ----------\n", " ");
		printf("%2d - %-10s%27s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%25s/\n", " ", " ");
		printf("%15s ----------%14s/\n", " ", " ");
		printf("%15s/%10s\\%12s/\n", " ", " ", " ");
		printf("%2d - %-10s%12s\\%10s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ", " ");
		printf("%27s ----------\n", " ");
		printf("%2d - %-10s%12s/\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name, " ");
		printf("%15s\\%10s/\n", " ", " ");
		printf("%15s ----------\n", " ");
		printf("%15s/\n", " ");
		printf("%2d - %-10s\n", ++id, tournament[SearchArrayIndexFromID(tournament, participantCount, id)].name);
		break;
	default:
		printf("Incorrect bracket size. Please create your bracket again.");
		break;
	}
}

// Searches the tournament for the index of a participant according to their ID
// if ID searched is not found in any participant return -1
int SearchArrayIndexFromID(PARTICIPANT tournament[], size_t tournamentSize, int searchID) {
	// initialize temporary index to 0 for safety
	int realIndex = 0;
	for (; realIndex <= tournamentSize && tournament[realIndex].id != searchID; realIndex++);

	// if ID is not found in array, return -1
	if (realIndex > tournamentSize)
		return -1;
	else	// returns index
		return realIndex;
}