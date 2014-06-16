#include "Player.h"

Player::Player(string name)
{
	this->Name = name;
	Anim.Static = IMG_Load("data/tiles/29.png");
}

Player::~Player()
{
	
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

Sprite Player::GetAnimations()
{
	return this->Anim;
}