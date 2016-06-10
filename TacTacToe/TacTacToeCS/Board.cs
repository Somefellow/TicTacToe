using System;
using System.Collections.Generic;

namespace TacTacToeCS
{
    class Board
    {
        Cell[] fGrid = new Cell[9];

        public int[] ValidMoves()
        {
            var lResult = new List<int>();

            for (int i = 0; i < fGrid.Length; i++)
            {
                if (fGrid[i] == Cell.BLANK)
                {
                    lResult.Add(i);
                }
            }

            return lResult.ToArray();
        }

        public Cell WinningPlayer()
        {
            if (Line(Cell.O))
            {
                return Cell.O;
            }

            if (Line(Cell.X))
            {
                return Cell.X;
            }

            return Cell.BLANK;
        }

        public bool Line(Cell aCell)
        {
            if (aCell == Cell.BLANK)
            {
                throw new Exception("Why bother checking to see if BLANK cells won the game?");
            }

            if (fGrid[4] == aCell) // If Centre matches.
            {
                if (fGrid[0] == aCell && fGrid[8] == aCell || fGrid[2] == aCell && fGrid[6] == aCell) // Check opposite corners.
                {
                    return true;
                }
            }

            for (int i = 0; i < 9; i += 3) // Horizontal.
            {
                if (fGrid[i] == aCell && fGrid[i + 1] == aCell && fGrid[i + 2] == aCell)
                {
                    return true;
                }
            }

            for (int i = 0; i < 3; i++) // Vertical.
            {
                if (fGrid[i] == aCell && fGrid[i + 3] == aCell && fGrid[i + 6] == aCell)
                {
                    return true;
                }
            }

            return false;
        }

        public void MakeMove(Cell aCell, int aIndex)
        {
            if (fGrid[aIndex] != Cell.BLANK)
            {
                throw new Exception("Cannot overwrite a value!");
            }

            fGrid[aIndex] = aCell;
        }
    }
}
