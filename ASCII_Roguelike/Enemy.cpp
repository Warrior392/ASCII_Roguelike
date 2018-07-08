#include "Enemy.h"



Enemy::Enemy(string name, char tile, int Health, int Damage, int ExpValue)
{
	_name = name;
	_tile = tile;
	_Health = Health;
	_Damage = Damage;
	_ExpValue = ExpValue;
}
