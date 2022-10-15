//
// Created by exalw on 13/10/22.
//

#define MAXC 12

#include <iostream>
using namespace std;
#include "RubixSide.h"
#include "colorParser.h"

//possible loss of numbers
void RubixSide::initSide(uint16_t mC, uint16_t *alMs, uint16_t *alCs) {
	int error = 0;
	if(mC<0||mC>MAXC) error = 1;
	/*if(sizeof(*alMs)<0||sizeof(*alMs)>5) error = 4;
	if(sizeof(*alMs)<0||sizeof(*alMs)>5) error = 5;*/
	for(int i=0;(i<5&&error==0);i++){
		if(alMs[i]<0||alMs[i]>MAXC) error = 2;
		if(alCs[i]<0||alCs[i]>MAXC) error = 3;
	}
	if(error!=0) {
		cout << "ERROR: "<<error << endl;
		return;
	}
	mainColor = mC;
	middleColors = alMs;
	cornerColors = alCs;
	return;
}

void RubixSide::printSide() {
	cout << "Side: " << mainColor << std::endl;
	char16_t a,b, *t;
	for(int i=0;i<5;i++){
		t = colorParser::nbrToC(cornerColors[i]);
		a = t[0]; b = t[1];
		cout << "Corner" << i << ": " << char(a) << char(b) << std::endl;
		t = colorParser::nbrToC(middleColors[i]);
		a = t[0]; b = t[1];
		cout << "Middle" << i << ": " <<  char(a) << char(b) << std::endl;
	}
	return;
}
