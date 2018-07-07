#include <iostream>
#include <conio.h>
#include <fstream>

#include "Player.h"
#include "Level.h"

using namespace std;

int main() {

	bool gameOver = false;

	Player player;
	Level level1("Level1.txt", player);
	level1.Print();
	printf("%s", string("Use w/a/s/d to move.").c_str());

	char key;

	while ((!gameOver))
	{

	//Player Controller

		key = _getch();
		
		switch (key) {
		case 'W':
		case 'w':
			if (level1.getChar(player.posX, player.posY-1) == '.')
			{
				player.posY--;
				level1.setChar(player.posX, player.posY + 1, '.');
			}
			break;
		case 'A':
		case 'a':
			if (level1.getChar(player.posX - 1, player.posY) == '.')
			{
				player.posX--;
				level1.setChar(player.posX + 1, player.posY, '.');
			}
			break;
		case 'S':
		case 's':
			if (level1.getChar(player.posX, player.posY + 1) == '.')
			{
				player.posY++;
				level1.setChar(player.posX, player.posY - 1, '.');
			}
			break;
		case 'D':
		case 'd':
			if (level1.getChar(player.posX + 1, player.posY) == '.')
			{
				player.posX++;
				level1.setChar(player.posX - 1, player.posY, '.');
			}
			break;
		}

		//Update player position and print the level

		player.setPosition(player.posX, player.posY);
		level1.setChar(player.posX, player.posY, '@');
		level1.Print();
	}

	system("PAUSE");
	return 0;
}
