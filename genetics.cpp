#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string.h>

#include "util.h"
#include "map.h"
#include "genetics.h"

#define RANDOM_NUM ((float)rand()/(RAND_MAX+1.0))

int bin2Dec(std::string bits){
	int value = 0;
	int baseval=1;
	for (int i = bits.length();i>0;--i){
		if (bits.at(i-1)=='1'){
			value+=baseval;
		}
	baseval*=2;
	}
	return value;

}

/*
Mutate runs a rng-based mutation. MUTATION_RATE must be veeery low,
otherwise everytime we run, we increase the chaotic level
*/

void mutate(std::string &bits){
	srand(time(NULL));
	for (int i=0; i<bits.length();++i){ //must: test backwards run fx
		if (RANDOM_NUM<= MUTATION_RATE){ //must: test diff between < and <=
			if (bits.at(i) == '1')
				bits.at(i) = '0';
			else
				bits.at(i) = '1';
		}
	}
}

/*Crossover function chooses a random position on a chromossome and chrosses two chromossomes.*/

void crossover(std::string &child1,std::string &child2){
	srand(time(NULL));
	if(RANDOM_NUM> CROSSOVER_RATE){
		int crosspoint = (RANDOM_NUM)*(CHROMO_LENGTH);
		std::string temp1;
		std::string temp2;
		temp1 = child1.substr(0,crosspoint) + child2.substr(crosspoint,CHROMO_LENGTH);
		temp2 = child2.substr(0,crosspoint) + child1.substr(crosspoint,CHROMO_LENGTH);
		child1 = temp1;
		child2 = temp2;
	}
}

/* The name explains itself. Returns a std::string with random zeroes and ones */

std::string generateRandomBits(int length){
	srand(time(NULL));
	std::string bits;
	for (int i=0;i<length;++i){
		if (RANDOM_NUM>0.5f){
			bits+="0"; //concatenate 0
		}
		else{
			bits+="1"; //concatenate 1
		}
	} //this function should be casted the fewer.
	return bits;
}

float evaluateFitness (Map map, std::string bits){
	Pos individual_pos = map.getStartPos();
	int current_gene = 0;
	Pos direction;
	for (int i = 0 ; i < CHROMO_LENGTH ; i+=GENE_LENGTH){
		current_gene = bin2Dec(bits.substr(i,GENE_LENGTH));
		direction.x = decodeDirection(current_gene).x + individual_pos.x;
		direction.y = decodeDirection(current_gene).y + individual_pos.y;
		if (map.isValid(direction)){
			individual_pos.x = direction.x;
			individual_pos.y = direction.y;
		}
		if (map.isEnd(individual_pos)){
			return 999.0f;
		}
	}
}

void printGeneSymbol(int val){
	switch(val){
		case 0:
			std::cout << "S";
			break;
		case 1:
			std::cout << "W";
			break;
		case 2:
			std::cout << "N";
			break;
		case 3:
			std::cout << "E";
			break;
	}
}

void printChromo(std::string bits){ //prints chromossomes
	for (int i=0;i<bits.length();++i){
		std::cout << bits.at(i) ;
		if ((i+1)%GENE_LENGTH==0 && i!=0)
			std::cout << " ";
	}
	std::cout << "\n";
	return ;
}

Pos decodeDirection(int val){
	switch(val){
		case 0:
			return SOUTH;
		case 1:
			return WEST;
		case 2:
			return NORTH;
		case 3:
			return EAST;
	}
}