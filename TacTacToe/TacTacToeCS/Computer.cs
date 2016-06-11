using System.Collections.Generic;

namespace TacTacToeCS
{
    class Computer : Player
    {
        bool fMaxPlayer;
        int fNextMove;

        public Computer(bool aMaxPlayer)
        {
            fMaxPlayer = aMaxPlayer;
        }

        public override int MakeMove(Board aBoard)
        {
            Minimax(aBoard, fMaxPlayer);
            return fNextMove;
        }

        int Minimax(Board aBoard, bool aMaxPlayer)
        {
            if (aBoard.GameOver())
            {
                return aBoard.WinningPlayer();
            }

            int[] lValidMoves = aBoard.ValidMoves();
            int lBestScore;

            if (aMaxPlayer)
            {
                lBestScore = int.MinValue;
                for (int i = 0; i < lValidMoves.Length; i++)
                {
                    int lValue = Minimax(new Board(aBoard, lValidMoves[i], 1), false);

                    if (lValue > lBestScore)
                    {
                        lBestScore = lValue;
                        fNextMove = lValidMoves[i];
                    }
                }
            }
            else
            {
                lBestScore = int.MaxValue;

                for (int i = 0; i < lValidMoves.Length; i++)
                {
                    int lValue = Minimax(new Board(aBoard, lValidMoves[i], 1), true);

                    if (lValue < lBestScore)
                    {
                        lBestScore = lValue;
                        fNextMove = lValidMoves[i];
                    }
                }
            }

            return lBestScore;
        }
    }
}
