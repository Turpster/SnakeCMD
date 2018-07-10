#include "Position.h"

Position::Position()
{
	this->x = 0;
	this->y = 0;
}

Position::Position(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}

Position::~Position()
{
	delete &(this->x);
	delete &(this->y);
}
