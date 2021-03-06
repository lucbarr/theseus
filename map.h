#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>

#include "util.h"

const int MAX_SIZE = 10;

class Map{
private:
	Pos startpos_;
	Pos endpos_;
	int n_of_rows_;
	int n_of_columns_;
public:
	std::string	map_[MAX_SIZE];
	Map(){};

	void setStartPos (Pos startpos) { startpos_ = startpos; }
	void setEndPos (Pos endpos) { endpos_ = endpos; }
	void setNofRows (int index) { n_of_rows_ = index; }
	void setNofColumns (int index) { n_of_columns_= index; }

	bool isEnd (Pos position) { return ((position.x == endpos_.x) && (position.y == endpos_.y)); }
	bool isStart (Pos position) { return ((position.x == startpos_.x) && (position.y == startpos_.y)); }
	bool isValid (Pos position) {
		if (map_[position.x].at(position.y) == '#') { return false; }
		return ((map_[position.x].at(position.y) == '.') || (map_[position.x].at(position.y) == 'x') || map_[position.x].at(position.y) == '@' );
	}

	int getNofRows() { return n_of_rows_; }
	int getNofColumns() { return n_of_columns_; }
	Pos getStartPos() { return startpos_; }
	Pos getEndPos() { return endpos_; }	

	void printMap(){
	for (int j=0 ; j < n_of_rows_ ; ++j){
		std::cout << map_[j] << std::endl;
	}
}
};

#endif 