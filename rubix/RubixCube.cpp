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

void RubixCube::setCoords(int *pS, int *pX, bool cw, int side){
	int mode=0;
	if(side<1) return;
	else if(side==1) mode=1;
	else if(side<7) {
		mode = 2;
		x[2-1][0]=side%5;
		s[2-1][1]=(side - 2 - 1 + 5) % 5 + 2;
		s[2-1][2]=(side - 7 + 4 + 5) % 5 + 7;
		s[2-1][3]=(side - 7 + 5 + 5) % 5 + 7;
		s[2-1][4]=(side - 2 + 1 + 5) % 5 + 2;
	} else if(side<12) {
		mode = 3;
		x[3-1][0]=-side+11;
		s[3-1][1]=(side - 7 + 1 + 5) % 5 + 7;
		s[3-1][2]=(side - 2 - 4 + 5) % 5 + 2;
		s[3-1][3]=(side - 2 - 5 + 5) % 5 + 2;
		s[3-1][4]=(side - 7 - 1 + 5) % 5 + 7;
	} else if(side==12) mode=4;

	if (cw) {
		for (int i = 0; i < 5; i++) {
			pS[i] = s[mode - 1][i];
			pX[i] = x[mode - 1][i];
		}
	} else {
		for (int i = 0; i < 5; i++) {
			pS[4 - i] = s[mode - 1][i];
			pX[4 - i] = x[mode - 1][i];
		}
	}
}

void RubixCube::moveEdgeCw(int data, int x0, int target, int y0){
	int x1 = (x0+1)%5;
	int y1 = (y0+1)%5;
	pSides[target].cornerColors[y0] = pSides[data].cornerColors[x0];
	pSides[target].middleColors[y0] = pSides[data].middleColors[x0];
	pSides[target].cornerColors[y1] = pSides[data].cornerColors[x1];
}

void RubixCube::turnEdgesCw(int* pS, int* pX){
	moveEdgeCw(pS[0], pX[0], 0, 0);
	moveEdgeCw(pS[4], pX[4], pS[0], pX[0]);
	moveEdgeCw(pS[3], pX[3], pS[4], pX[4]);
	moveEdgeCw(pS[2], pX[2], pS[3], pX[3]);
	moveEdgeCw(pS[1], pX[1], pS[2], pX[2]);
	moveEdgeCw(0, 0, pS[1], pX[1]);
	emptyBuffer();
	return;
}

void RubixCube::updateOtherSides(int side, bool cw) {
	int *pX = new int[5];
	int *pS = new int[5];
	setCoords(pS,pX,cw,side);
	turnEdgesCw(pS, pX);
	return;
}

void RubixCube::turnSideC(int side){
	cout << "Turning Side: " << side << " - clockwise" << endl;
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
	updateOtherSides(side, true);
}

void RubixCube::turnSideCC(int side){
	cout << "Turning Side: " << side << " - counterclockwise" << endl;
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
	updateOtherSides(side, false);
}

void RubixCube::printCube() {
	for(int i=1;i<13;i++){
		pSides[i].printSide();
	}
	cout << endl;
}
