#include <string>

#include "Player.h"

Player::Player(string name)
{
	this->Name = name;
}

void Player::SetPosition(int x, int y)
{
	this->Position["x"] = x;
	this->Position["y"] = y;
}

Coords Player::GetPosition()
{
	return this->Position;
}
