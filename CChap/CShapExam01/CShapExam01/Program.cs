using System;

namespace CShapExam01
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] birthYear = new int[100];
            Console.WriteLine("최대 100명까지 태어난 연도를 입력하세요. (2021 이상 입력시 종료)");

            int sel = 0;
            int i = 0;
            for(; i<100; i++)
            {
                sel = int.Parse(Console.ReadLine());
                if (sel > 2021)
                    break;
                birthYear[i] = sel;
            }
            Console.WriteLine();
            Console.WriteLine("아래로 나이가 순서대로 출력됩니다.");
            int Age = 0;
            String[] ment = new String[6] { "유아", "어린이", "청소년", "청년", "중년", "노년" };
            for (int j = 0; j < i; j++)
            {
                Age = AskAge(birthYear[j]);
                Console.WriteLine("나이 : " + birthYear[j] + ", 연령대 : " + ment[Age]);
            }
                

        }
        static int AskAge(int birthyear)
        {
            int Age = 2021 - birthyear + 1;
            if (Age < 7)
                return 0;
            else if (Age < 13)
                return 1;
            else if (Age < 20)
                return 2;
            else if (Age < 30)
                return 3;
            else if (Age < 60)
                return 4;
            else if (Age > 60)
                return 5;
            else return 6;
        }
    }
  
}
