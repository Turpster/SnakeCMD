#include "Handler.h"
#include "Program.h"
#include "Entity.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <list>

Handler::Handler()
{
	this->addEntity(*(new Player(*(new Position(3, 3)), *(new Vector(1, 0)), '+', '~')));
}


Handler::~Handler()
{

}

void Handler::tick()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("CLS");

	for (int y = 0; y <= Program::height; y++)
	{
		for (int x = 0; x <= Program::width; x++)
		{
			if (y == 0 || y == Program::height)
			{
				std::cout << '#';
			}
			else if (x == 0 || x == Program::width)
			{
				std::cout << '#';
			}
			else if (getEntityHere(x, y) == nullptr)
			{
				std::cout << '-';
			}
			else
			{
				this->getEntityHere(x, y)->render(x, y);
			}
		}
		std::cout << std::endl;
	}
	for (std::list<Entity>::iterator it = this->entities.begin(); it != this->entities.end(); std::advance(it, 1))
	{
		it->tick();
	}

}
void Handler::addEntity(const Entity& entity)
{
	this->entities.insert(this->entities.begin(), entity);
}

Entity* Handler::getEntityHere(const int& x, const int& y)
{
	for (std::list<Entity>::iterator it = this->entities.begin(); it != this->entities.end(); std::advance(it, 1))
	{
		if (it->pos.x == x && it->pos.y == y)
		{
			return &(*it);
		}
	}
	return nullptr;
}