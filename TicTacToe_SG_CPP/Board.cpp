#include "Board.h"

Board::Board()
{
}

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

int Board::WinningPlayer()
{
	if (Line(1))
	{
		return 1;
	}
	else if (Line(-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Board::Line(int aValue)
{
	if (aValue == 0)
	{
		throw std::exception("Why?");
	}

	if (fGrid.at(4) == aValue) // If Centre matches.
	{
		if (fGrid.at(0) == aValue && fGrid.at(8) == aValue || fGrid.at(2) == aValue && fGrid.at(6) == aValue) // Check opposite corners.
		{
			return true;
		}
	}

	for (int i = 0; i < 9; i += 3) // Horizontal.
	{
		if (fGrid.at(i) == aValue && fGrid.at(i + 1) == aValue && fGrid.at(i + 2) == aValue)
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++) // Vertical.
	{
		if (fGrid.at(i) == aValue && fGrid.at(i + 3) == aValue && fGrid.at(i + 6) == aValue)
		{
			return true;
		}
	}

	return false;
}

void Board::MakeMove(int aIndex, int aValue)
{
	if (fGrid.at(aIndex) != 0)
	{
		throw std::exception("Cannot overwrite a value!");
	}

	fGrid.at(aIndex) = aValue;
}

void Board::Draw()
{
	for (int i = 0; i < 2; i++)
	{
		//draw_rectangle(ColorBlack, (float)(i % 3 * 200), (float)(i / 3 * 200), 200, 200);
		switch (1)
		//switch (fGrid.at(i))
		{
		case -1:
			draw_circle(ColorBlack, (float)(i % 3 * 200) + 100, (float)(i / 3 * 200) + 100, 100);
			break;
		case 1:
			draw_line(ColorBlack, (float)((i % 3) * 200), (float)((i / 3) * 200), (float)((i % 3) * 200), (float)((i % 3) * 200));
			//draw_line(ColorBlack, (float)(i % 3 * 200) + 200, (float)(i / 3 * 200), (float)(i % 3 * 200), (float)(i % 3 * 200) + 200);
			break;
		}
	}
}
