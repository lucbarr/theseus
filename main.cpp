#include <iostream>
#include <fstream>
#include <string>

#include "util.h"

using namespace std;

const int MAX_SIZE = 10;

void printMap(string map[MAX_SIZE], int rows){
	for (int j=0 ; j < rows ; ++j){
		cout << map[j] << endl;
	}
}

int main (){
	Pos startpos, endpos;
	ifstream mapfile;
	string map[MAX_SIZE];
	int i= 0;
	mapfile.open ("map.txt");
	while (!mapfile.eof()){
		getline(mapfile,map[i]);
		if(map[i].find_first_of("i") != string::npos){
			startpos.x = i;
			startpos.y = map[i].find_first_of("i");
		}
		if(map[i].find_first_of("@") != string::npos){
			endpos.x = i;
			endpos.y = map[i].find_first_of("@");
		}
		i++;
	}
}

