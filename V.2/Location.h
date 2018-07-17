#pragma once
struct Location
{
	int x, y;

	Location(int x, int y)
		: x(x), y(y) {};

	bool operator==(const Location& other)
	{
		return this->x == other.x && this->y == other.y;
	};

	bool operator!=(const Location& other)
	{
		return !(operator==(other));
	}
};

