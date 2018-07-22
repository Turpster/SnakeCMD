#include "Input.h"
#include <iostream>
#include <conio.h>
#include <thread>

class Game
{
public:
	void KeyPressed(char key);
};

Input::Input(Game* gameins) : thread(std::thread(&(Input::s_start), this)), game(gameins)
{

}

void Input::s_start(Input* ins)
{
	ins->start();
}

void Input::start()
{
	while (true)
	{
		char input = _getch();
		game->KeyPressed(input);
	}
}

Input::~Input()
{

}
