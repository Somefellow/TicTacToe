using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TacTacToeCS
{
    class Human : Player
    {
        public override int MakeMove(Board aBoard)
        {
            string lInput;
            int lInt;

            while (true)
            {
                lInput = Console.ReadLine();

                if (int.TryParse(lInput, out lInt))
                {
                    foreach (int i in aBoard.ValidMoves())
                    {
                        if (lInt == i)
                        {
                            return lInt;
                        }
                    }
                }

                Console.WriteLine("Invalid move...");
            }
        }
    }
}
