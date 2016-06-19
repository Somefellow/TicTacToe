#pragma once
#include "Board.h"
class Computer
{
private:
	static int Minimax(Board, bool);
public:
	static int MakeMove(Board);
};