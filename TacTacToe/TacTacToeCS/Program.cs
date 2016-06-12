using System;

namespace TacTacToeCS
{
    class Program
    {
        static void Main(string[] args)
        {
            new Match(new Computer(true), new Computer(false)).PlayGame();

            Console.ReadLine();
        }
    }
}
