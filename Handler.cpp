#include "Handler.h"
#include "Program.h"
#include <chrono>
#include <thread>
#include <iostream>

Handler::Handler()
{
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
			if (!(x == this->player.pos.x && y == this->player.pos.y))
			{
				if (y == 0 || y == Program::height)
				{
					std::cout << '#';
				}
				else if (x == 0 || x == Program::width)
				{
					std::cout << '#';
				}
				else
				{
					std::cout << '-';
				}
			}
			else
			{
				this->player.render(x, y);
			}
		}
		std::cout << std::endl;
	}

	this->player.tick();
}
