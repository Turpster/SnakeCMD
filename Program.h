#pragma once

#include "Handler.h"

class Program
{
protected:
	Handler handler;
public:
	static const int const width = 70; static const int const height = 20;

	bool running = false;

	Program();
	int start();
	void stop();
	int run();

	~Program();
};

