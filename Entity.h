#pragma once
#include <iostream>
#include "Position.h"
#include "Vector.h"
#include "Entity.h"

class Entity
{
public:
	Position pos;
	Vector vector;

	char model, trail;

	Entity(const Position& pos, const Vector& vector, const char& model, const char& trail);
	void tick();
	void render(const int& x, const int& y);
	
	~Entity();
};

