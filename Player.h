#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(const Position& pos, const Vector& vector, const char& model, const char& trail);

	~Player();
};

