#pragma once

#include "Entity.h"
#include <list>

class Player : public Entity
{
public:
	std::list<Position> trailLocs;
	void addTrail(const Position* pos);
	char Trail;
	int TrailSize;

	void tick() override;
	void render(const int& x, const int& y) override;
	Player(const Position& pos, const Vector& vector, const char& model, const char& trail, const int& trailsize);
	~Player();
};

