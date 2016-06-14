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
            if (aBoard.GameOver()) return aBoard.WinningPlayer();

            int[] lValidMoves = aBoard.ValidMoves();
            int lBestScore;
            int lBestMove = new int();

            if (aMaxPlayer) lBestScore = int.MinValue;
            else            lBestScore = int.MaxValue;

            for (int i = 0; i < lValidMoves.Length; i++)
            {
                int lValue = Minimax(new Board(aBoard, lValidMoves[i], aMaxPlayer ? 1 : -1), !aMaxPlayer);

                if (aMaxPlayer && lValue > lBestScore || !aMaxPlayer && lValue < lBestScore)
                {
                    lBestScore = lValue;
                    lBestMove = lValidMoves[i];
                }
            }

            fNextMove = lBestMove;
            return lBestScore;
        }
    }
}
