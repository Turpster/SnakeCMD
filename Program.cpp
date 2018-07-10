#include "Program.h"
#include <iostream>

Program::Program() 
{
	system("color F0");
}

int Program::start()
{
	this->running = true;
	return this->run();
};
void Program::stop()
{
	this->running = false;
};
int Program::run()
{
	while (this->running)
	{
		this->handler.tick();
	}
	return 0;
};
Program::~Program()
{
	delete &(this->handler);
	delete &(this->running);
};
