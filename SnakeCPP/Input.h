#pragma once
#include <iostream>
#include "mingw-std-threads/mingw.thread.h"

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

