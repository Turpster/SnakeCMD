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
	Position oldPos = this->pos;
	Entity::tick();
	this->addTrail(oldPos);
	std::cout << "Testing" << std::endl;
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
