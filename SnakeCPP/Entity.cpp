#include "Entity.h"
#include "Location.h"
#include "Game.h"
#include <iostream>

Entity::Entity(const Location& loc, const Vector& vec, const char& model) : loc(loc), vec(vec), model(model) {}

void Entity::tick()
{
	if ((loc.x + vec.xv + 1 < Game::WIDTH && loc.x + vec.xv > 0)) loc.x += vec.xv;
	if ((loc.y + vec.yv + 1 < Game::HEIGHT && loc.y + vec.yv > 0)) loc.y += vec.yv;
}

void Entity::render(int x, int y)
{
	Location oloc(x, y);
	if (this->loc == oloc)
	{
		std::cout << model;
	}
}

Entity::~Entity()
{

}
