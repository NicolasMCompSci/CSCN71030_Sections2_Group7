#pragma once


#define MAXNAME 10

typedef struct participant
{
	char name[MAXNAME];
	int id;
	int group_id;
}PARTICIPANT;


void printmenu(PARTICIPANT* participants, int num);
void random(PARTICIPANT* participants, int num);
void mannual(PARTICIPANT* participants, int num);
void assign(PARTICIPANT* participants, int num);
