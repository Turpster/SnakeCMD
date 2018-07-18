#include "Player.h"
#include "Entity.h"
#include "Location.h"
#include <iostream>

Player::Player(const Location& loc, const Vector& vec, const char& model, const char& tail, int tailsize)
	: Entity(loc, vec, model), tail(tail), tailsize(tailsize)
{
	
}

void Player::tick()
{
	Location oldloc = this->loc;
	Entity::tick();

	if (oldloc != this->loc)
	{
		this->addTail(oldloc);
	}
}

void Player::addTail(const Location& tloc)
{
	if (this->tailLocs.size() == this->tailsize)
	{
		this->tailLocs.erase(this->tailLocs.begin());
	}
	
	this->tailLocs.insert(this->tailLocs.end(), *(new Location(tloc.x, tloc.y)));
}

void Player::render(int x, int y)
{
	Entity::render(x, y);

	for (Location& loc : this->tailLocs)
	{
		if (loc.x == x && loc.y == y && loc != this->loc)
		{
			std::cout << this->tail;
		}
	}
}

Player::~Player()
{
	for (Location loc : this->tailLocs)
	{
		delete &loc;
	}
}