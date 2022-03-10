using System;
using System.Collections.Generic;
using System.Text;

namespace TextGame
{
    class GameController
    {
        private GameCharacter char1;
        private GameCharacter char2;

        //생성자
        public GameController()
        {
            char1 = new GameCharacter(10, 50, 2);
            char2 = new GameCharacter(10, 20, 2);
        }

        public void MainGameLoop()
        {
            while (true)
            {
                char1.ShowAll();
                Console.WriteLine();
                char2.ShowAll();
                Console.WriteLine();

                Console.WriteLine("1. 공격, 2. 나가기");
                Console.Write("커맨드를 입력하세요 >> ");
                int command = int.Parse(Console.ReadLine());

                switch (command)
                {
                    case 1:
                        char1.Attack(char2);
                        break;
                    case 2:
                        Console.WriteLine("나가기를 시도 했습니다.");
                        break;
                    default:
                        Console.WriteLine("잘못된 커맨드입니다.");
                        break;
                }
                if (char2.IsAlive())
                    char2.Attack(char1);
                else
                {
                    Console.WriteLine("승리했습니다.");
                    break;
                }
                if (!char1.IsAlive())
                {
                    Console.WriteLine("패배했습니다.");
                    break;
                }
            }
        }
    }
}
