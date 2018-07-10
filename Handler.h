#pragma once
#include <list>
#include "Player.h"
#include "Position.h"
#include "Vector.h"
class Handler
{
public:

	Player player = *(new Player(*(new Position(3, 3)), *(new Vector(1, 0)), '+', '~'));

	Handler();
	~Handler();
	void tick();
};

