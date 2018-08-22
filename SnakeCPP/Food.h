#pragma once

#include "Entity.h"

class Food : public Entity
{
public:
	Food(const Location& loc, const Vector& vec, const char& model);
	~Food();
	void tick() override;
	void render(int x, int y) override;
};

