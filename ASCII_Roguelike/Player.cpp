#include "Player.h"
#include <string>

using namespace std;

Player::Player()
{
}

void Player::printStats() {
	printf("  Health: %d	Defence: %d\n", Health, Defence);
	printf("  Exp: %d	Level: %d	Gold: %d\n", Experience, Level, Gold);
}
