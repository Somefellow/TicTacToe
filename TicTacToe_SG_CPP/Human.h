#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Human();
	~Human();
	int MakeMove(Board);
};
