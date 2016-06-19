#pragma once
#include <array>
#include <allegro5\allegro_primitives.h>
#include "Define.h"
class Board
{
private:
	std::array<int, 9> fGrid;
public:
	Board();
	Board(Board&);
	~Board();
	bool ValidMove(int);
	bool GameOver();
	int WinningPlayer();
	bool Line(int);
	void MakeMove(int, int);
	void Draw();
	bool FullBoard();
};