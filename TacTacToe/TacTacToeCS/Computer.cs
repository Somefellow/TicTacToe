using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TacTacToeCS
{
    class Computer : Player
    {
        public Computer() : base(false)
        {
        }

        public override int MakeMove(Board aBoard)
        {
            throw new NotImplementedException();
        }
    }
}
