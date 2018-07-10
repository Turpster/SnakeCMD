#include "Vector.h"

Vector::Vector(const int& xv, const int& yv)
{
	this->xv = xv;
	this->yv = yv;
}

Vector::Vector()
{
	this->xv = 0;
	this->yv = 0;
}

Vector::~Vector()
{
	delete &(this->xv);
	delete &(this->yv);
}
