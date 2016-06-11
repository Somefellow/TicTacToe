using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TacTacToeCS
{
    class Tree
    {
        readonly Board fData;
        Tree[] fNodes;

        public Tree(Board aData, int aSize)
        {
            fData = aData;
            fNodes = new Tree[aSize];
        }
    }
}
