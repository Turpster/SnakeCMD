#include "Game.h"
#include "Player.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <cstdlib>
#include <ctime>


Game::Game() : player(Location(0, 0), Vector(1, 0), '+', '~', 4), food(Location(0, 0), Vector(0, 0), '@'), input(this)
{
	system("COLOR 0F");

	srand(time(0));
	player.loc.x = (rand() % (Game::WIDTH - 2)) + 1;
	player.loc.y = (rand() % (Game::HEIGHT - 2)) + 1;

	food.loc.x = (rand() % (Game::WIDTH - 2)) + 1;
	food.loc.y = (rand() % (Game::HEIGHT - 2)) + 1;
}

void Game::KeyPressed(char key)
{
	switch (key)
	{
	case 'a': //left
		player.vec.xv = -1;
		player.vec.yv = 0;
		return;
	case 'w': //up
		player.vec.xv = 0;
		player.vec.yv = -1;
		return;
	case 'd': //right
		player.vec.xv = 1;
		player.vec.yv = 0;
		return;
	case 's': //sdown
		player.vec.xv = 0;
		player.vec.yv = 1;
		return;
	default:
		return;
	}
}

int Game::Run()
{
	this->m_Running = true;
	while (this->m_Running)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / this->m_TicksPS));
		this->Tick();
	}
	return 0;
}

void Game::Tick()
{
	system("CLS");

	//render
	for (int y = 0; y < Game::HEIGHT; y++)
	{
		for (int x = 0; x < Game::WIDTH; x++)
		{
			if (y == 0 || y == Game::HEIGHT - 1)
			{
				std::cout << '#';
			}
			else if (x == 0 || x == Game::WIDTH - 1)
			{
				std::cout << '#';
			}
			else if (getEntityHere(x, y) != nullptr)
			{
				getEntityHere(x, y)->render(x, y);
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

	//game-tick
	this->player.tick();
	this->food.tick();

	if (player.loc == food.loc)
	{
		player.tailsize++;
		food.loc.x = (rand() % (Game::WIDTH - 2)) + 1;
		food.loc.y = (rand() % (Game::HEIGHT - 2)) + 1;
	}

	std::cout << "X: " << food.loc.x << std::endl;
	std::cout << "Y: " << food.loc.y << std::endl;
}

Entity* Game::getEntityHere(int x, int y)
{
	Location loc(x, y);
	
	if (loc == this->player.loc)
	{
		return &(this->player);
	}
	else if (loc == this->food.loc)
	{
		return &(this->food);
	}
	for (Location tailLoc : this->player.tailLocs)
	{
		if (tailLoc == loc)
		{
			return &player;
		}
	}
	return nullptr;
}

void Game::Stop()
{
	this->m_Running = false;	
}

Game::~Game()
{

}
