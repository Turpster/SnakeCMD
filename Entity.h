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

	char model;

	Entity(const Position& pos, const Vector& vector, const char& model);
	virtual void tick();
	virtual void render(const int& x, const int& y);
	
	~Entity();
};

