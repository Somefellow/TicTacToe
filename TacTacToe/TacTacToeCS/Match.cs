using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TacTacToeCS
{
    class Match
    {
        Board fBoard;
        readonly Player fX;
        readonly Player fO;

        public Match(Player aPlayer)
        {
            Contract.Requires(aPlayer != null);

            fX = aPlayer;
            fO = new Computer();
            fBoard = new Board();
        }

        public void PlayGame()
        {
            while (fBoard.WinningPlayer() == 0)
            {
            }
        }
    }
}
