#pragma once
#include <array>
class Board
{
private:
	std::array<int, 9> fGrid;
public:
	Board(Board&);
	~Board();
	bool ValidMove(int aIndex);
	bool GameOver();
};

