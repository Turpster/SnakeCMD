#pragma once
#include <iostream>
#include <thread>

class Game;

class Input
{
private:
	std::thread thread;

	void static s_start(Input* ins);

	void start();
protected:
	Game* game;
public:
	Input(Game* gameins);

	~Input();
};

