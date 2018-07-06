#pragma once
class Player
{
public:
	Player();
	void setPosition(int x, int y) { posX = x; posY = y; }

	int posX;
	int posY;
};

