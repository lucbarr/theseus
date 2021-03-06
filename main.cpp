#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "util.h"
#include "map.h"
#include "chromo.h"
#include "genetics.h"

using namespace std;

int main (){
	srand(time(NULL));
	Pos startpos, endpos;
	ifstream mapfile;
	Map map;
	int i = 0;
	int index=0;
	float totalFitness = 0.0f;
	mapfile.open ("map.txt");
	while (!mapfile.eof()){
		getline(mapfile, map.map_[i]);
		if(map.map_[i].find_first_of("i") != string::npos){
			startpos.x = i;
			startpos.y = map.map_[i].find_first_of("i");
			map.setStartPos(startpos);
		}
		if(map.map_[i].find_first_of("@") != string::npos){
			endpos.x = i;
			endpos.y = map.map_[i].find_first_of("@");
			map.setEndPos(endpos);
		}
		i++;
	}
	map.setNofRows(i);
	map.setNofColumns(map.map_[0].length());
	ChromoType population[POP_SIZE];
	for (int i = 0 ; i < POP_SIZE ; ++i){
		population[i].bits = generateRandomBits(CHROMO_LENGTH);
	}
	int popPopper;
	cout << pathGoneDiff(map);
	while (true){
		totalFitness = fitnessSum(population);
		index = checkSolve(population);
		if (population[index].fitness > 990){
			break;
		}
		system ("clear");
		usleep(16666);
		ChromoType tempPop[POP_SIZE];
		popPopper=0;
		while (popPopper < POP_SIZE){
			string child1 = roulette(totalFitness, population); 
			string child2 = roulette(totalFitness, population);
			crossover(child1,child2);
			mutate(child1);
			mutate(child2);
			tempPop[popPopper].bits = child1;
			tempPop[popPopper++].fitness = printPath(map, child1);
			tempPop[popPopper].bits = child2;
			tempPop[popPopper++].fitness = printPath(map, child2);
			system("clear");
		}
		for (int i=0;i<POP_SIZE;++i){
			population[i].bits = tempPop[i].bits;
			population[i].fitness = tempPop[i].fitness;
		}
	}
	printPath(map, population[index].bits);
	return 0;
}