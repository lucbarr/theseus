#ifndef GENETICS_H
#define GENETICS_H

#include <string>
#include "map.h"

int bin2Dec(std::string bits);

void mutate(std::string &bits);
void crossover(std::string &child1,std::string &child2);
std::string generateRandomBits(int length);
void printGeneSymbol(int val);
void printChromo(std::string bits);
float evaluateFitness (Map map, std::string bits);
Pos decodeDirection(int val);

#endif