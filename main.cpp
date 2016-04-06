#include <iostream>
#include <fstream>
#include <string>

struct Pos{
	int x,y;
};

using namespace std;

const int MAX_SIZE = 10;

void printMap(string map[MAX_SIZE], int rows);

int main (){
	Pos startPos, endPos;
	ifstream mapfile;
	string map[MAX_SIZE];
	int i= 0;
	mapfile.open ("map.txt");
	while (!mapfile.eof()){
		getline(mapfile,map[i]);
		if(map[i].find_first_of("i") != string::npos){
			startPos.x = i;
			startPos.y = map[i].find_first_of("i");
		}
		if(map[i].find_first_of("@") != string::npos){
			endPos.x = i;
			endPos.y = map[i].find_first_of("@");
		}
		i++;
	}
	printMap (map, i);
	cout << startPos.x << " , " << startPos.y << endl;
	cout << endPos.x << " , " << endPos.y << endl;
}

void printMap(string map[MAX_SIZE], int rows){
	for (int j=0 ; j < rows ; ++j){
		cout << map[j] << endl;
	}
}