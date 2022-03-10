using System;

namespace CShapProject01
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Console.Write("태어난 연도를 입력하시오 : ");
            int birthYear = int.Parse(Console.ReadLine());
            int age = 2021 - birthYear + 1;
            Console.WriteLine("나이 : " + age);

            if (age < 7)
                Console.WriteLine("유아 입니다.");
            else if (age < 13)
                Console.WriteLine("어린이 입니다.");
            else if (age < 20)
                Console.WriteLine("청소년 입니다.");
            else if (age < 30)
                Console.WriteLine("청년 입니다.");
            else if (age < 60)
                Console.WriteLine("중년 입니다.");
            else
                Console.WriteLine("노년 입니다.");
            */

            Console.Write("숫자를 입력하세요 : ");
            int x = int.Parse(Console.ReadLine());
            if (x > 1)
            {
                Console.Write("1부터 " + x + "까지 더한 값 : ");
                for (int index = x - 1; index > 0; index--)
                    x += index;
                Console.WriteLine(x);
            }
            else
                Console.WriteLine("입력값이 1보다 작습니다.");

            return;
            
        }
    }
}
