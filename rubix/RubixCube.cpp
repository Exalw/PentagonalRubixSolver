//
// Created by exalw on 13/10/22.
//

#include "RubixCube.h"

#include <iostream>
using namespace std;

/**
 * Initializes Cube with all Numbers/Colors
 * Side 0 is a buffer, should always be reemptied
 * Side 1 is up, Side 2 is front, Side 3-6 is cw around,
 * Side 7 is left under Side 2, Side 8-11 go around c, Side 12 is down
 * @param alNbrs cotains 120 nbrs for PentagonalCube
 */
void RubixCube::init(uint16_t* alNbrs) {
	//tmp sol
	uint16_t* mCs = new uint16_t[13];
	for(int i=0;i<13;i++) mCs[i] = i;

	RubixSide* tmpRS = new RubixSide;
	uint16_t* tmpMs = new uint16_t[5];
	uint16_t* tmpCs = new uint16_t[5];
	tmpRS->initSide(mCs[0], tmpMs,tmpCs);   //Buffer Init.
	pSides[0] = *tmpRS;

	for(int i=1;i<13;i++){                                //Cube Init.
		tmpMs = new uint16_t[5];
		tmpCs = new uint16_t[5];
		for(int j=0;j<5;j++){
			tmpCs[j] = alNbrs[(i-1)*10+(j*2)];
			tmpMs[j] = alNbrs[(i-1)*10+((j*2)+1)];
		}
		tmpRS->initSide(mCs[i], tmpMs,tmpCs);
		pSides[i] = *tmpRS;
	}
}

void RubixCube::emptyBuffer() {
	pSides->cornerColors = new uint16_t[5];
	pSides->middleColors = new uint16_t[5];
}

void RubixCube::updateOtherSidesC(int side) {
	int *pX,*pS;
	if (side < 1) return;
	else if (side == 1) {
		int x[5] = {0, 0, 0, 0, 0};
		pX = x;
		int s[5] = {2, 3, 4, 5, 6};
		pS = s;
	} else if (side < 7) {
		int x[5] = {side%5, 4, 4, 0, 1};
		pX = x;
		int s[5] = {1, (side - 2 - 1 + 5) % 5 + 2, (side - 7 + 4 + 5) % 5 + 7,
		            (side - 7 + 5 + 5) % 5 + 7, (side - 2 + 1 + 5) % 5 + 2};
		pS = s;
	} else if (side < 12){
		int x[5] = {-side+11, 1, 2, 3, 3};
		pX = x;
		int s[5] = {12, (side - 7 + 1 + 5) % 5 + 7, (side - 2 - 4 + 5) % 5 + 2,
		            (side - 2 - 5 + 5) % 5 + 2, (side - 7 - 1 + 5) % 5 + 7};
		pS = s;
	}
	else if(side==12) {
		int x[5] = {2, 2, 2, 2, 2};
		pX = x;
		int s[5] = {11, 10, 9, 8, 7};
		pS = s;
	}
	turnEdgesCw(pS, pX);
	return;
}

void RubixCube::turnEdgesCw(int* s, int* x){
	moveEdgeCw(s[0], x[0], 0, 0);
	moveEdgeCw(s[4], x[4], s[0], x[0]);
	moveEdgeCw(s[3], x[3], s[4], x[4]);
	moveEdgeCw(s[2], x[2], s[3], x[3]);
	moveEdgeCw(s[1], x[1], s[2], x[2]);
	moveEdgeCw(0, 0, s[1], x[1]);
	emptyBuffer();
	return;
}

void RubixCube::moveEdgeCw(int data, int x0, int target, int y0){
	int x1 = (x0+1)%5;
	int y1 = (y0+1)%5;
	pSides[target].cornerColors[y0] = pSides[data].cornerColors[x0];
	pSides[target].middleColors[y0] = pSides[data].middleColors[x0];
	pSides[target].cornerColors[y1] = pSides[data].cornerColors[x1];
}

void RubixCube::turnSideC(int side){
	cout << "Turning Side: " << side << endl;
	RubixSide rS = pSides[side];
	uint16_t* tmpCs = new uint16_t[5];
	uint16_t* tmpMs = new uint16_t[5];
	for(int i=0;i<4;i++){
		tmpCs[i] = rS.cornerColors[i+1];
		tmpMs[i] = rS.middleColors[i+1];
	}
	tmpCs[4] = rS.cornerColors[0];
	tmpMs[4] = rS.middleColors[0];
	rS.cornerColors = tmpCs;
	rS.middleColors = tmpMs;
	updateOtherSidesC(side);
}

void RubixCube::turnSide(int side){
	RubixSide rS = pSides[side];
	uint16_t* tmpCs = new uint16_t[5];
	uint16_t* tmpMs = new uint16_t[5];
	for(int i=0;i<4;i++){
		tmpCs[i+1] = rS.cornerColors[i];
		tmpMs[i+1] = rS.middleColors[i];
	}
	tmpCs[0] = rS.cornerColors[4];
	tmpMs[0] = rS.middleColors[4];
	rS.cornerColors = tmpCs;
	rS.middleColors = tmpMs;

}

void RubixCube::printCube() {
	for(int i=1;i<13;i++){
		pSides[i].printSide();
	}
	cout << endl;
}

void RubixCube::solve() {

}
