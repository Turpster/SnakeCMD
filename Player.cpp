#include "Player.h"

Player::Player(const Position& pos, const Vector& vector, const char& model, const char& trail, const int& trailsize)
	: Entity(pos, vector, model)
{
	this->Trail = trail;
	this->TrailSize;
}
Player::~Player()
{

}
void Player::tick()
{
	Position oldPos = this->pos;
	Entity::tick();

	if (!(this->pos.x == oldPos.x && this->pos.y == oldPos.y))
	{
		Player::addTrail(oldPos);
	}
}

void Player::addTrail(const Position& pos)
{
	if (this->trailLocs.size() == this->TrailSize)
	{
		this->trailLocs.erase(trailLocs.begin());
	}

	this->trailLocs.insert(trailLocs.end(), pos);
}

void Player::render(const int& x, const int& y)
{
	Entity::render(x, y);
}
