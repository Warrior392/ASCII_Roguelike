#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int Health, int Damage, int ExpValue);

private:
	string _name;
	char _tile;

	int _Health;
	int _Damage;
	int _ExpValue;
};

