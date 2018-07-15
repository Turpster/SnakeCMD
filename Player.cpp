#include "Player.h"

Player::Player(const Position& pos, const Vector& vector, const char& model, const char& trail, const int& trailsize)
	: Entity(pos, vector, model)
{
	this->Trail = trail;
	this->TrailSize = trailsize;
}
Player::~Player()
{
	Entity::~Entity();
	delete &(this->TrailSize);
	delete[] &(this->trailLocs);
	delete &(this->Trail);
}
void Player::tick()
{
	Position trailpos(this->pos.x, this->pos.y);
	Entity::tick();
	this->addTrail(new Position(trailpos.x, trailpos.y));
}

void Player::addTrail(const Position* pos)
{
	if (this->trailLocs.size() == this->TrailSize)
	{
		this->trailLocs.pop_front();
		this->trailLocs.insert(trailLocs.end(), *pos);
	}
	else
	{
		this->trailLocs.insert(trailLocs.end(), *pos);
	}
}

void Player::render(const int& x, const int& y)
{
	Entity::render(x, y);
	for (Position& pos : this->trailLocs)
	{
		if (pos.x == x && pos.y == y)
		{
			std::cout << this->Trail;
		}
	}
}
