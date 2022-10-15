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
	void updateOtherSidesC(int side);
	void turnEdgesCw(int *s, int *x);
	void moveEdgeCw(int data, int x0, int target, int x1);
	void turnSideC(int side);
	void turnSideCC(int side);

	void printCube();
};


#endif //PENTAGONALRUBIX_RUBIXCUBE_H
