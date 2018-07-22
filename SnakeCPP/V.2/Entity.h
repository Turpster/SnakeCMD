#pragma once
#include "Location.h"
#include "Vector.h"

class Entity
{
public:
	Location loc;
	Vector vec;
	char model;

	Entity(const Location& loc, const Vector& vec, const char& model);
	virtual void tick();
	virtual void render(int x, int y);
	~Entity();
};