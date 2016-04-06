#include <iostream>
#include <fstream>
#include <string>

#include "util.h"
#include "map.h"

using namespace std;

int main (){
	Pos startpos, endpos;
	ifstream mapfile;
	Map map;
	int i= 0;
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
	map.printMap();	
	printPos(map.getEndPos());
	printPos(map.getStartPos());

}