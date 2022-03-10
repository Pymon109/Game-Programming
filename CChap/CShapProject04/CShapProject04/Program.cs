using System;

namespace CShapProject04
{
    class Program
    {
        static void Main(string[] args)
        {
            GameCharacter character1 = new GameCharacter(100);
            GameCharacter character2 = new GameCharacter(50);

            character1.ShowAll();
            character2.ShowAll();

            character1.levelup();

            Console.WriteLine();
            character1.ShowAll();
            character2.ShowAll();

            Console.WriteLine();
            Monster mon1 = new Monster(0, 100);
            mon1.ShowAll();
        }
    }
}
