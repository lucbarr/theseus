#ifndef UTIL_H
#define UTIL_H

#include <string>

struct Pos{
	int x,y;
};

const float CROSSOVER_RATE = 0.7;
const float MUTATION_RATE = 0.002;
const unsigned int POP_SIZE = 50;
const unsigned int CHROMO_LENGTH = 128;
const unsigned int GENE_LENGTH = 2;
const unsigned int MAX_ALLOWABLE_GENERATIONS = 1000;
const unsigned int BUFF_MAX = 256;

#endif