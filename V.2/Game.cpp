#include "Game.h"
#include <chrono>
#include <thread>
#include <iostream>

Game::Game() {}

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
	std::cout << "Hello World" << std::endl;
}

void Game::Stop()
{
	this->m_Running = false;	
}

Game::~Game()
{

}
