using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TacTacToeCS
{
    abstract class Player
    {
        bool fPlayer;

        /// <summary>
        ///
        /// </summary>
        /// <param name="aPlayer">True for player, false for AI</param>
        protected Player(bool aPlayer)
        {
            fPlayer = aPlayer;
        }

        public abstract int MakeMove(Board aBoard);
    }
}
