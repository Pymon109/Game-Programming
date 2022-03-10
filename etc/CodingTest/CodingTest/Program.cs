using System;

namespace CodingTest
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int lenth = int.Parse(input[0]);
            int standard = int.Parse(input[1]);
            string[] sequence = Console.ReadLine().Split(' ');
            for (int i = 0 ; i < lenth ; i++)
            {
                if (standard > int.Parse(sequence[i]))
                    Console.Write(sequence[i] + " ");
            }
        }
    }
}
