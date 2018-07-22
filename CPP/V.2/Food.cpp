#include "Food.h"
#include "Entity.h"
#include <iostream>

Food::Food(const Location& loc, const Vector& vec, const char& model) 
	: Entity(loc, vec, model) {}

void Food::tick()
{
	Entity::tick();
}

void Food::render(int x, int y)
{
	if (Location(x, y) == this->loc)
	{
		std::cout << this->model;
	}
}

Food::~Food()
{

}

