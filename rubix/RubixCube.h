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

public:
	void init(uint16_t* alNbrs);

	void emptyBuffer();
	void turnOtherSidesC(int side);
	void turnCornerSidesCw(int *s, int *x);
	void turnCornerSidesCwFT(int s0, int s1, int s2, int s3, int s4);
	void turnCornerSidesCwFMT(int s, int s0, int s1, int s2, int s3, int s4);
	void turnCornerSidesCwFMD(int s, int s0, int s1, int s2, int s3, int s4);
	void turnCornerSidesCwFD(int s0, int s1, int s2, int s3, int s4);
	void moveEdgeCw(int data, int x0, int target, int x1);
	void turnSideC(int side);
	void turnSide(int side);

	void printCube();
	void solve();
};


#endif //PENTAGONALRUBIX_RUBIXCUBE_H
