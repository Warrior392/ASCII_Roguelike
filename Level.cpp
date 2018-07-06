#include "Level.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Level::Level(string fileName, Player &player)
{
	ifstream level(fileName);
	if (level.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string row;
	while (getline(level, row)) {
		_levelData.push_back(row);
	}

	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile)
			{
			case '@':
				player.setPosition(j, i);
				break;
			}
		}
	}
}

void Level::Print() {
	cout << string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n",_levelData[i].c_str());
	}
	printf("\n");
}
