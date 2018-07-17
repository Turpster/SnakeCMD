#pragma once
class Game
{
protected:
	bool m_Running = false;
public:
	static const int m_TicksPS = 60;

	static const int WIDTH; 
	static const int HEIGHT;

	Game();
	int Run();
	void Stop();
	void Tick();
	~Game();
};

