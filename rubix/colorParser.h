//
// Created by exalw on 14/10/22.
//

#ifndef PENTAGONALRUBIX_COLORPARSER_H
#define PENTAGONALRUBIX_COLORPARSER_H

class colorParser {
public:
	static uint16_t cToNbr(char16_t *c);

	static char16_t* nbrToC(uint16_t nbr);
};


#endif //PENTAGONALRUBIX_COLORPARSER_H
