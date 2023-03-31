#pragma once

#define MAXNAMESIZE 10

typedef struct participant {
	char name[MAXNAMESIZE];
	int id;
	int group_id;
}PARTICIPANT;