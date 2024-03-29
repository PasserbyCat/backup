#ifndef MAP_H
#define MAP_H

#include "rlutil/rlutil.h"

class Map
{
public:
	Map();
	char getplace();
	bool move();
	void met();
private:
	bool first = true;
	std::string map[31];
	bool moveavailable(char k);
	int x = 20; 
	int y = 31; 
	unsigned int cnt = 0;
};

#endif // !MAP_H


