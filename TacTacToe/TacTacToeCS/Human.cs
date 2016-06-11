using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TacTacToeCS
{
    class Human : Player
    {
        public Human() : base(true)
        {
        }

        public override int MakeMove(Board aBoard)
        {
            throw new NotImplementedException();
        }
    }
}
