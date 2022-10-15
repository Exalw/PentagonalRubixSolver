#include <iostream>
#include "rubix/RubixCube.h"

/**
 * Rubix Cube Solver for pentagonal Sides
 * First Color: Above, third is clockwise from second (sides), last is down.
 * Sides are clockwise starting from first one in above left corner
 * @return
 */
int main() {
	RubixCube* c = new RubixCube();
	std::cout << "Hello, World! Let`s test that Cube!" << std::endl;
	std::cout << "TestCube is all done" << std::endl;
	uint16_t* alNbrs = new uint16_t[120];
	const int tmpNbrs[120] = {1,1,1,1,1,1,1,1,1,1,
							  2,2,2,2,2,2,2,2,2,2,
							  3,3,3,3,3,3,3,3,3,3,
							  4,4,4,4,4,4,4,4,4,4,
							  5,5,5,5,5,5,5,5,5,5,
							  6,6,6,6,6,6,6,6,6,6,
							  7,7,7,7,7,7,7,7,7,7,
							  8,8,8,8,8,8,8,8,8,8,
							  9,9,9,9,9,9,9,9,9,9,
							  10,10,10,10,10,10,10,10,10,10,
							  11,11,11,11,11,11,11,11,11,11,
							  12,12,12,12,12,12,12,12,12,12};
	for(int k=0;k<120;k++){
		alNbrs[k] = tmpNbrs[k];
	}
	c->init(alNbrs);
	c->printCube();
	c->turnSideC(2);
	c->printCube();
	return 0;
}
