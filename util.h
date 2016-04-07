#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>

struct Pos{
	int x,y;
};


const Pos NORTH = {0,-1};
const Pos SOUTH = {0,1};
const Pos EAST = {1,0};
const Pos WEST = {-1,0};

const float CROSSOVER_RATE = 0.8;
const float MUTATION_RATE = 0.02f;
const unsigned int POP_SIZE = 50;
const unsigned int CHROMO_LENGTH = 128;
const unsigned int GENE_LENGTH = 2;
const unsigned int MAX_ALLOWABLE_GENERATIONS = 1000;
const unsigned int BUFF_MAX = 256;

inline void printPos(Pos position){
	std::cout << "( " <<  position.x << " , " << position.y << " )";
}
inline char dirSymbol(int val){
	switch(val){
		case 0:
			return 'S';
		case 1:
			return 'W';
		case 2:
			return 'N';
		case 3:
			return 'E';
	}
}

#endif