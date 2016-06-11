using System;
using System.Collections.Generic;

namespace TacTacToeCS
{
    class Board
    {
        int[] fGrid;
        bool fTurn;

        public Board()
        {
            fGrid = new int[9];
        }

        public Board(Board aBoard)
        {
            fGrid = aBoard.fGrid.Clone() as int[];
        }

        public int[] ValidMoves()
        {
            var lResult = new List<int>();

            for (int i = 0; i < fGrid.Length; i++)
            {
                if (fGrid[i] == 0)
                {
                    lResult.Add(i);
                }
            }

            return lResult.ToArray();
        }

        public int WinningPlayer()
        {
            if (Line(1))
            {
                return 1;
            }

            if (Line(-1))
            {
                return -1;
            }

            return 0;
        }

        public bool Line(int aValue)
        {
            if (aValue == 0)
            {
                throw new Exception("Why?");
            }

            if (fGrid[4] == aValue) // If Centre matches.
            {
                if (fGrid[0] == aValue && fGrid[8] == aValue || fGrid[2] == aValue && fGrid[6] == aValue) // Check opposite corners.
                {
                    return true;
                }
            }

            for (int i = 0; i < 9; i += 3) // Horizontal.
            {
                if (fGrid[i] == aValue && fGrid[i + 1] == aValue && fGrid[i + 2] == aValue)
                {
                    return true;
                }
            }

            for (int i = 0; i < 3; i++) // Vertical.
            {
                if (fGrid[i] == aValue && fGrid[i + 3] == aValue && fGrid[i + 6] == aValue)
                {
                    return true;
                }
            }

            return false;
        }

        public void MakeMove(int aIndex, int aValue)
        {
            if (fGrid[aIndex] != 0)
            {
                throw new Exception("Cannot overwrite a value!");
            }

            fGrid[aIndex] = aValue;
        }
    }
}
