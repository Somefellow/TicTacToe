using System;

namespace TacTacToeCS
{
    class Program
    {
        static void Main(string[] args)
        {
            new Match(new Human(), new Computer(false)).PlayGame();

            Console.ReadLine();
        }
    }
}
