#pragma once

#include "Handler.h"

class Program
{
protected:
	Handler handler;
public:
	const static int width = 70;
	const static int height = 20;

	bool running = false;

	Program();
	int start();
	void stop();
	int run();

	~Program();
};

