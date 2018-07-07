#pragma once
#include <vector>

#include "Player.h"

using namespace std;

class Level
{
public:
	Level(string fileName, Player &player);
	void setChar(int x, int y, char tile) { _levelData[y][x] = tile; }
	char getChar(int x, int y) { return _levelData[y][x]; }
	void Print();

private:
	vector<string> _levelData;
};

