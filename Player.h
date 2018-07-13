#pragma once

#include "Entity.h"
#include <list>

class Player : public Entity
{
private:
	void addTrail(const Position& pos);
public:
	std::list<Position> trailLocs;

	char Trail;
	int TrailSize;

	void tick() override;
	void render(const int& x, const int& y);

	Player(const Position& pos, const Vector& vector, const char& model, const char& trail, const int& trailsize);
	~Player();
};

