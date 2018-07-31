#pragma once

#include "Player.h"
#include "Location.h"
#include "Vector.h"
#include "Food.h"
#include "Input.h"

class Game
{
protected:
	bool m_Running = false;

	void randPos(Entity& entity);
public:
	Player player;
	Food food;
	Input input;

	static const int m_TicksPS = 15;

	static const int WIDTH = 25; 
	static const int HEIGHT = 10;

	Entity* getEntityHere(int x, int y);

	void KeyPressed(char key);
	
	Game();
	int Run();
	void Stop();
	void Tick();
	~Game();
};

