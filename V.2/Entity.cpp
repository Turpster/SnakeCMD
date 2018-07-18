#include "Entity.h"
#include "Location.h"
#include <iostream>

Entity::Entity(const Location& loc, const Vector& vec, const char& model) : loc(loc), vec(vec), model(model) {}

void Entity::tick()
{
	loc.x += vec.xv;
	loc.y += vec.yv;
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
