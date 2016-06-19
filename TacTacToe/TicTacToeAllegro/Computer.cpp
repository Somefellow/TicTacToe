#include "Computer.h"

int Computer::Minimax(Board aBoard, bool aMax)
{
	if (aBoard.GameOver())
	{
		return aBoard.WinningPlayer();
	}

	int lBestScore;

	if (aMax)	lBestScore = -2;
	else		lBestScore = 2;

	for (int i = 0; i < 9; i++)
	{
		if (aBoard.ValidMove(i))
		{
			Board Copy(aBoard);
			Copy.MakeMove(i, aMax ? 1 : -1);

			int lValue = Minimax(Copy, !aMax);

			if ((aMax && lValue > lBestScore) || (!aMax && lValue < lBestScore))
			{
				lBestScore = lValue;
			}
		}
	}

	return lBestScore;
}

int Computer::MakeMove(Board aBoard)
{
	int lBestScore = 1;
	int lBestMove = -1;

	for (int i = 0; i < 9; i++)
	{
		if (aBoard.ValidMove(i))
		{
			Board Copy(aBoard);
			Copy.MakeMove(i, -1);

			int lCurrentScore = Minimax(Copy, true);

			if (lCurrentScore < lBestScore)
			{
				lBestScore = lCurrentScore;
				lBestMove = i;
			}
		}
	}

	return lBestMove;
}