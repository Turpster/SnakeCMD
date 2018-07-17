#pragma once
#include "Entity.h"
#include <list>

class Player : public Entity
{
public:
	char tail;
	int tailsize;

	std::list<Location> tailLocs;

	Player(const Location& loc, const Vector& vec, const char& model, const char& tail, int tailsize);

	void addTail(const Location& loc);
	void tick() override;
	void render(int x, int y) override;
	~Player();
};