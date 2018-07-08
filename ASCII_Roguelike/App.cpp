#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>

#include "Player.h"
#include "Level.h"


using namespace std;

void ControlPlayer(Level &level, Player &player);
void reprintGameToConsole(Level currentLevel, Player player);
bool checkTile(char direction, Level level, Player player, char tile);

bool gameOver = false;
int Floor = 1;

int main() {

	Player player;
	Level level1("Level1.txt", player);
	level1.Print();

	Level currentLevel = level1;

	printf("  %s\n", string("Use (w/a/s/d) to move.").c_str());
	printf("  %s\n", string("# - Wall   * - 1 Gold").c_str());
	printf("  %s\n", string(". - Air").c_str());
	printf("  %s\n", string("@ - You").c_str());

	while ((!gameOver))
	{
		//Player Controller
		ControlPlayer(currentLevel, player);

		//Update player position and print the level
		reprintGameToConsole(currentLevel, player);
	}

	system("PAUSE");
	return 0;
}

void ControlPlayer(Level &level, Player &player) {
	char key;
	key = _getch();

	switch (key) {
	case 'W':
	case 'w':
		if (checkTile('w', level, player, '.' ) || checkTile('w', level, player, '*'))
		{
			if (level.getChar(player.posX, player.posY - 1) == '*') { player.Gold++; }

			player.posY--;
			level.setChar(player.posX, player.posY + 1, '.');
		}
		break;
	case 'A':
	case 'a':
		if (checkTile('a', level, player, '.') || checkTile('a', level, player, '*'))
		{
			if (level.getChar(player.posX - 1, player.posY) == '*') { player.Gold++; }

			player.posX--;
			level.setChar(player.posX + 1, player.posY, '.');
		}
		break;
	case 'S':
	case 's':
		if (checkTile('s', level, player, '.') || checkTile('s', level, player, '*'))
		{
			if (level.getChar(player.posX, player.posY + 1) == '*') { player.Gold++; }

			player.posY++;
			level.setChar(player.posX, player.posY - 1, '.');
		}
		break;
	case 'D':
	case 'd':
		if (checkTile('d', level, player, '.') || checkTile('d', level, player, '*'))
		{
			if (level.getChar(player.posX + 1, player.posY) == '*') { player.Gold++; }

			player.posX++;
			level.setChar(player.posX - 1, player.posY, '.');
		}
		break;
	}
}

void reprintGameToConsole(Level currentLevel, Player player) {
	player.setPosition(player.posX, player.posY);
	currentLevel.setChar(player.posX, player.posY, '@');
	currentLevel.Print();
	printf("  Floor: %d\n\n", Floor);
	player.printStats();
}

bool checkTile(char direction, Level level, Player player, char tile) {
	switch (direction) {
	case 'w':
		if (level.getChar(player.posX, player.posY - 1) == tile) { return true; }
		break;
	case 'a':
		if (level.getChar(player.posX - 1, player.posY) == tile) { return true; }
		break;
	case 's':
		if (level.getChar(player.posX, player.posY + 1) == tile) { return true; }
		break;
	case 'd':
		if (level.getChar(player.posX + 1, player.posY) == tile) { return true; }
		break;
	}
	return false;
}