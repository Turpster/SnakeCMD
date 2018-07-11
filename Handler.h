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
	std::list<Entity> entities;

	Handler();
	~Handler();
	void tick();
	void addEntity(const Entity& entity);
	Entity* getEntityHere(const int& x, const int& y);
};

