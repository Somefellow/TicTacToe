#pragma once
#include <array>
#include "SwinGame.h"
class Board
{
private:
	std::array<int, 9> fGrid;
public:
	Board();
	Board(Board&);
	~Board();
	bool ValidMove(int aIndex);
	bool GameOver();
	int WinningPlayer();
	bool Line(int);
	void MakeMove(int, int);
	void Draw();
};

