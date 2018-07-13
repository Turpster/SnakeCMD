#include "Handler.h"
#include "Program.h"
#include "Entity.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <list>

Handler::Handler()
{
	this->addEntity(*(new Player(*(new Position(3, 3)), *(new Vector(1, 0)), '+', '~', 4)));
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
	for (auto &entity : this->entities)
	{
		entity.tick();
	}

}
void Handler::addEntity(const Entity& entity)
{
	this->entities.insert(this->entities.begin(), entity);
}

Entity* Handler::getEntityHere(const int& x, const int& y)
{
	for (auto &entity : this->entities)
	{
		if (entity.pos.x == x && entity.pos.y == y)
		{
			return &entity;
		}
		Player* player = dynamic_cast<Player*>(&entity);
		
		if (player)
		{
			for (auto &pos : player->trailLocs)
			{
				if (pos.x == player->pos.x && pos.y == player->pos.y)
				{
					return &entity;
				}
			}
		}
	}
	return nullptr;
}