#include "Board.h"

Board::Board(Board& aBoard)
{
	fGrid = aBoard.fGrid;
}

Board::~Board()
{
}

bool Board::ValidMove(int aIndex)
{
	if (aIndex < 0)
	{
		throw std::underflow_error("");
	}
	else if (aIndex >= 9)
	{
		throw std::overflow_error("");
	}
	else
	{
		return fGrid.at(aIndex) == 0;
	}
}

bool Board::GameOver()
{
	if (WinningPlayer() != 0)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (fGrid.at(i) == 0)
			{
				return false;
			}
		}

		return true;
	}
}
