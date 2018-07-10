#include "Entity.h"
#include "Position.h"
#include "Vector.h"

Entity::Entity(const Position& pos, const Vector& vector, const char const model, const char const trail)
{
	this->pos = pos;
	this->vector = vector;
	this->model = model;
	this->trail = trail;
}

void Entity::tick()
{
	this->pos.x += this->vector.xv;
	this->pos.y += this->vector.yv;

void Entity::render(const int& x, const int& y)
{
	if (x == (this->pos.x) && y == (this->pos.y))
	{
		std::cout << this->model;
	}
}

Entity::~Entity()
{
	delete &(this->pos);
	delete &(this->vector);
	delete &(this->model);
	delete &(this->trail);
}


