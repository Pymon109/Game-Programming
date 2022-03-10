using System;

namespace CShapProject02
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] scoreList = new int[10];
            int maxNum = 0, minNum = 100, total = 0;
            float average = 0;

            for(int i = 0; i < 10; i++)
            {
                Console.Write((i+1) + "번째 점수를 입력하세요 : ");
                scoreList[i] = int.Parse(Console.ReadLine());
            }
            for(int i = 0; i <10; i++)
            {
                if(maxNum < scoreList[i])
                    maxNum = scoreList[i];
                if (minNum > scoreList[i])
                    minNum = scoreList[i];
                total += scoreList[i];
            }

            Console.WriteLine("최고점 : " + maxNum);
            Console.WriteLine("최저점 : " + minNum);
            Console.WriteLine("총합 : " + total);

            total -= (maxNum + minNum);
            average = total / 8;

            Console.WriteLine("최고,최저 제외 평균 : " + average);

        }
    }
}
