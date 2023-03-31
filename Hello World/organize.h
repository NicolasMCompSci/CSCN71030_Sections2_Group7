#pragma once


#define MAXNAMESIZE 10

typedef struct participant {
	char name[MAXNAMESIZE];
	int id;
	int group_id;
}PARTICIPANT;


void printmenu(PARTICIPANT* participants, int num);
void random(PARTICIPANT* participants, int num);
void mannual(PARTICIPANT* participants, int num);
void assign(PARTICIPANT* participants, int num);
