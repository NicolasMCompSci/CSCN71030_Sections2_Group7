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
	PARTICIPANT p[64];
	p[0].id = 1, strcpy(p[0].name, "p0");
	p[1].id = 2, strcpy(p[1].name, "p1");
	p[2].id = 3, strcpy(p[2].name, "p2");
	p[3].id = 4, strcpy(p[3].name, "p3");
	p[4].id = 5, strcpy(p[4].name, "p4");
	p[5].id = 6, strcpy(p[5].name, "p5");
	p[6].id = 7, strcpy(p[6].name, "p6");
	p[7].id = 8, strcpy(p[7].name, "p7");
	p[8].id = 9, strcpy(p[8].name, "p8");
	p[9].id = 10, strcpy(p[9].name, "p9");
	p[10].id = 11, strcpy(p[10].name, "p10");
	p[11].id = 12, strcpy(p[11].name, "p11");
	p[12].id = 13, strcpy(p[12].name, "p12");
	p[13].id = 14, strcpy(p[13].name, "p13");
	p[14].id = 15, strcpy(p[14].name, "p14");
	p[15].id = 16, strcpy(p[15].name, "p15");
	p[16].id = 17, strcpy(p[16].name, "p16");
	p[17].id = 18, strcpy(p[17].name, "p17");
	p[18].id = 19, strcpy(p[18].name, "p18");
	p[19].id = 20, strcpy(p[19].name, "p19");
	p[20].id = 21, strcpy(p[20].name, "p20");
	p[21].id = 22, strcpy(p[21].name, "p21");
	p[22].id = 23, strcpy(p[22].name, "p22");
	p[23].id = 24, strcpy(p[23].name, "p23");
	p[24].id = 25, strcpy(p[24].name, "p24");
	p[25].id = 26, strcpy(p[25].name, "p25");
	p[26].id = 27, strcpy(p[26].name, "p26");
	p[27].id = 28, strcpy(p[27].name, "p27");
	p[28].id = 29, strcpy(p[28].name, "p28");
	p[29].id = 30, strcpy(p[29].name, "p29");
	p[30].id = 31, strcpy(p[30].name, "p30");
	p[31].id = 32, strcpy(p[31].name, "p31");
	p[32].id = 33, strcpy(p[32].name, "p32");
	p[33].id = 34, strcpy(p[33].name, "p33");
	p[34].id = 35, strcpy(p[34].name, "p34");
	p[35].id = 36, strcpy(p[35].name, "p35");
	p[36].id = 37, strcpy(p[36].name, "p36");
	p[37].id = 38, strcpy(p[37].name, "p37");
	p[38].id = 39, strcpy(p[38].name, "p38");
	p[39].id = 40, strcpy(p[39].name, "p39");
	p[40].id = 41, strcpy(p[40].name, "p40");
	p[41].id = 42, strcpy(p[41].name, "p41");
	p[42].id = 43, strcpy(p[42].name, "p42");
	p[43].id = 44, strcpy(p[43].name, "p43");
	p[44].id = 45, strcpy(p[44].name, "p44");
	p[45].id = 46, strcpy(p[45].name, "p45");
	p[46].id = 47, strcpy(p[46].name, "p46");
	p[47].id = 48, strcpy(p[47].name, "p47");
	p[48].id = 49, strcpy(p[48].name, "p48");
	p[49].id = 50, strcpy(p[49].name, "p49");
	p[50].id = 51, strcpy(p[50].name, "p50");
	p[51].id = 52, strcpy(p[51].name, "p51");
	p[52].id = 53, strcpy(p[52].name, "p52");
	p[53].id = 54, strcpy(p[53].name, "p53");
	p[54].id = 55, strcpy(p[54].name, "p54");
	p[55].id = 56, strcpy(p[55].name, "p55");
	p[56].id = 57, strcpy(p[56].name, "p56");
	p[57].id = 58, strcpy(p[57].name, "p57");
	p[58].id = 59, strcpy(p[58].name, "p58");
	p[59].id = 60, strcpy(p[59].name, "p59");
	p[60].id = 61, strcpy(p[60].name, "p60");
	p[61].id = 62, strcpy(p[61].name, "p61");
	p[62].id = 63, strcpy(p[62].name, "p62");
	p[63].id = 64, strcpy(p[63].name, "p63");


	//DisplayTournament_Short(p, 64);
	DisplayTournament_Full(p, 64);
}