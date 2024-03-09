#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(class Game* game);
	virtual ~GameObject();

	class Game* game() { return Game; }

private:
	class Game* Game = 0;
};

