#pragma once

struct Vector
{
	int xv, yv;

	Vector(int xv, int yv) : xv(xv), yv(yv) {};

	bool operator==(const Vector& other)
	{
		return this->xv == other.xv && this->yv == other.yv;
	};
};