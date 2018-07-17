#pragma once

#include "Player.h"
#include "Location.h"
#include "Vector.h"
#include "Food.h"

class Game
{
protected:
	bool m_Running = false;
public:
	Player player;
	Food food;

	static const int m_TicksPS = 5;

	static const int WIDTH = 70; 
	static const int HEIGHT = 25;

	Entity* getEntityHere(int x, int y);
	
	Game();
	int Run();
	void Stop();
	void Tick();
	~Game();
};

