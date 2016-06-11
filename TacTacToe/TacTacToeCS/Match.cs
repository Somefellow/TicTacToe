using System;

namespace TacTacToeCS
{
    class Match
    {
        readonly Board fBoard;
        readonly Player fX;
        readonly Player fO;
        bool fIsXTurn;

        public Match(Player aPlayer1, Player aPlayer2)
        {
            fX = aPlayer1;
            fO = aPlayer2;
            fBoard = new Board();
            fIsXTurn = true;
        }

        public void PlayGame()
        {
            while (!fBoard.GameOver())
            {
                Console.WriteLine(fBoard);

                Console.WriteLine("---");

                if (fIsXTurn)
                {
                    fBoard.MakeMove(fX.MakeMove(fBoard), 1);
                    fIsXTurn = false;
                }
                else
                {
                    fBoard.MakeMove(fO.MakeMove(fBoard), -1);
                    fIsXTurn = true;
                }

                Console.WriteLine("---");
            }

            switch (fBoard.WinningPlayer())
            {
                case 1:
                    Console.WriteLine("X Wins!");
                    break;
                case -1:
                    Console.WriteLine("O Wins!");
                    break;
                default:
                    Console.WriteLine("It was a draw!");
                    break;
            }
        }
    }
}
