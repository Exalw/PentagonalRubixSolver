//
// Created by exalw on 13/10/22.
//

#ifndef PENTAGONALRUBIX_RUBIXCUBE_H
#define PENTAGONALRUBIX_RUBIXCUBE_H


#include "RubixSide.h"
#include "colorParser.h"

/*
 * Might be a standard/pentagonal duodecahedron, but for simplicity,
 * I will refer to it as a cube.
 * A pentagonal Cube with 12 faces, that is.
 */
class RubixCube {
private:
	RubixSide *pSides = new RubixSide[13];
	int x[4][5] = {{0, 0, 0, 0, 0},
				   {-1, 4, 4, 0, 1},
				   {-1, 1, 2, 3, 3},
				   {2, 2, 2, 2, 2}};
	int s[4][5] = {{2, 3, 4, 5, 6},
				   {1, -1, -1,-1, -1},
				   {12, -1, -1,-1, -1},
				   {11, 10, 9, 8, 7}};

public:
	void init(uint16_t* alNbrs);

	void emptyBuffer();
	void setCoords(int *pS, int *pX, bool cw, int s);
	void moveEdgeCw(int data, int x0, int target, int x1);
	void turnEdgesCw(int *pS, int *pX);
	void updateOtherSides(int side, bool cw);
	void turnSideC(int side);
	void turnSideCC(int side);

	void printCube();
};


#endif //PENTAGONALRUBIX_RUBIXCUBE_H
