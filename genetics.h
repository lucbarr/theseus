#ifndef GENETICS_H
#define GENETICS_H

int bin2Dec(string bits);

void mutate(string &bits);
void crossover(string &child1,string &child2);
string generateRandomBits(int length);
void printGeneSymbol(int val);
void printChromo(string bits);

#endif