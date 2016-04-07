#ifndef GENETICS_H
#define GENETICS_H

#include <string>
#include "map.h"
#include "chromo.h"

int bin2Dec(std::string bits);
float distSqr(Pos pos1, Pos pos2);

void mutate(std::string &bits);
void crossover(std::string &child1,std::string &child2);
std::string generateRandomBits(int length);
std::string roulette (float fitnessSum, ChromoType* population);
float pathGoneDiff(Map map);

void printGeneSymbol(int val);
void printChromo(Map map,std::string bits);
//float evaluateFitness (Map map, std::string bits);
float fitnessSum(ChromoType* population);
Pos decodeDirection(int val);
int checkSolve(ChromoType* population);

float printPath(Map map, std::string bits);

#endif