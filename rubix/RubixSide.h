//
// Created by exalw on 13/10/22.
//

#ifndef PENTAGONALRUBIX_RUBIXSIDE_H
#define PENTAGONALRUBIX_RUBIXSIDE_H

#include <cstdint>

#define TWO_JQK_OF_A_KIND 10;


class RubixSide {
public:

	uint16_t mainColor;
	char *mainColorName = new char[10];
	uint16_t *middleColors = new uint16_t[5];
	uint16_t *cornerColors = new uint16_t[5];


	/*
	 * alMs & alCs should have five colors
	 */
	void initSide(uint16_t mC, uint16_t *alMs, uint16_t *alCs);

	void printSide();

};
#endif //PENTAGONALRUBIX_RUBIXSIDE_H
