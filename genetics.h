#ifndef GENETICS_H
#define GENETICS_H

int bin2Dec(std::string bits);

void mutate(std::string &bits);
void crossover(std::string &child1,std::string &child2);
std::string generateRandomBits(int length);
void printGeneSymbol(int val);
void printChromo(std::string bits);

#endif