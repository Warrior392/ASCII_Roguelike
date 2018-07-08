#pragma once
class Player
{
public:
	Player();
	void setPosition(int x, int y) { posX = x; posY = y; }
	void printStats();

	int posX;
	int posY;

	int Health = 100;
	int Defence = 0;
	int Experience = 0;
	int Level = 1;
	int Gold = 25;
};

