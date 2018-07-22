#pragma once
#include <iostream>
#include <list>
#include "Player.h"
#include "Entity.h"
#include "Position.h"
#include "Vector.h"

class Handler
{
public:
	std::list<Entity*> entities;

	Handler();
	~Handler();
	void tick();
	Entity* getEntityHere(const int& x, const int& y);
};

