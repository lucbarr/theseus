#ifndef CHROMO_H
#define CHROMO_H

#include <string.h>

struct ChromoType{ //we create a struct type for chromossomes
 	std::string bits;
 	float fitness;

 	ChromoType():bits(" "),fitness(0.0f){}; // init if uncasted
 	ChromoType(std::string bts,float ftns):bits(bts),fitness(ftns){} //init if casted
 };
 
 #endif