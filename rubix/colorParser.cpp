//
// Created by exalw on 14/10/22.
//

#include <stdint-gcc.h>
#include "colorParser.h"

char16_t* colorParser::nbrToC(uint16_t nbr) {
	char16_t* c = new char16_t[2];
	switch(nbr){
		case 1:
			c[0]='W';
			c[1]='h';
			break;
		case 2:
			c[0]='B';
			c[1]='l';
			break;
		case 3:
			c[0]='R';
			c[1]='e';
			break;
		case 4:
			c[0]='G';
			c[1]='r';
			break;
		case 5:
			c[0]='P';
			c[1]='u';
			break;
		case 6:
			c[0]='Y';
			c[1]='e';
			break;
		case 7:
			c[0]='R';
			c[1]='o';
			break;
		case 8:
			c[0]='B';
			c[1]='e';
			break;
		case 9:
			c[0]='C';
			c[1]='y';
			break;
		case 10:
			c[0]='O';
			c[1]='r';
			break;
		case 11:
			c[0]='L';
			c[1]='i';
			break;
		case 12:
			c[0]='G';
			c[1]='y';
			break;
		case 0:
			c[0]='0';
			c[1]=0;
			break;
		default:
			*c=-1;
			break;
	}
	return c;
}

/**
 *
 * @param c - has a minimum of 2 chars
 * @return
 */
uint16_t colorParser::cToNbr(char16_t *c) {
	uint16_t nbr = 0;
	switch (c[0]) {
		case 'W':
			nbr=1;
			break;
		case 'B':
			switch(c[1]){
				case 'l':
					nbr=2;
					break;
				case 'e':
					nbr=8;
					break;
			}
		case 'R':
			switch(c[1]){
				case 'e':
					nbr=3;
					break;
				case 'o':
					nbr=7;
					break;
			}
		case 'G':
			switch(c[1]){
				case 'r':
					nbr=4;
					break;
				case 'y':
					nbr=12;
					break;
			}
		case 'P':
			nbr=5;
			break;
		case 'Y':
			nbr=6;
			break;
		case 'C':
			nbr=9;
			break;
		case 'O':
			nbr=10;
			break;
		case 'L':
			nbr=11;
			break;
		case '0':
			nbr=0;
			break;
		default:
			nbr=-1;
			break;
	}/*
	switch(*c){
		case 'Wh':
			nbr=1;
		case 'Bl':
			nbr=2;
		case 'Re':
			nbr=3;
		case 'Gr':
			nbr=4;
		case 'Pu':
			nbr=5;
		case 'Ye':
			nbr=6;
		case 'Ro':
			nbr=7;
		case 'Be':
			nbr=8;
		case 'Cy':
			nbr=9;
		case 'Or':
			nbr=10;
		case 'Li':
			nbr=11;
		case 'Gy':
			nbr=12;
		default:
			nbr=-1;
	}*/
	return nbr;
}
