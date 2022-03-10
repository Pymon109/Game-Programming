using System;

namespace CShapProject03
{
    class Program
    {
        static void Main(string[] args)
        {
            /*            int select = 0, total = 0;
                        int[] menu = new int[4] { 15000, 10000, 70000, 20000 };
                        while (true)
                        {
                            ShowMenu();
                            Console.Write("번호 선택하세요 : ");
                            select = int.Parse(Console.ReadLine());
                            if (select == 5)
                                break;
                            total += menu[select - 1];
                            Console.WriteLine("현재 합계 : " + total +" 원");
                        }
                        Console.WriteLine("최종 합계 : " + total + " 원");*/

            /* Console.Write("섭씨 온도를 입력하세요 : ");
             float Cel = float.Parse(Console.ReadLine());
             Console.WriteLine("변환 결과 : " + CtoF(Cel));*/

            /*Console.Write("숫자를 입력하세요 : ");
            int num = int.Parse(Console.ReadLine());
            printTri(num);*/

            


        }

        static void ShowMenu()
        {
            Console.WriteLine(">> 메뉴판");
            Console.WriteLine("==============================================");
            Console.WriteLine("   메뉴     가격");
            Console.WriteLine("1. 피자     15,000 원");
            Console.WriteLine("2. 스파게티 10,000 원");
            Console.WriteLine("3. 샐러드   7,000 원");
            Console.WriteLine("4. 음료수   2,000 원");
            Console.WriteLine("5. 종료");
            Console.WriteLine("==============================================");
        }
        static double CtoF(float Celsius)
        {
            double Fahrenheit = (Celsius * 1.8) + 32;
            return Fahrenheit;
        }
        static double m2toPyung (float m2)
        {
            double pyung = m2 / 3.305;
            return pyung;
        }
        static void printTri(int n)
        {
            for(int i = 0; i < n+1; i++)
            {
                for (int j = 0; j < i + 1; j++)
                    Console.Write("*");
                Console.WriteLine();
            }

        }
        static void printRightBlankTri(int height, int blank)
        {
            int dyBlank = height;
            for(int i = 0; i <height; i++)
            {
                //최소 여백 출력
                for (int j = 0; j < blank; j++)
                    Console.Write(" ");
                //오른쪽으로 붙이는 여백
                for (int k = 0; k<(height-i-1);k++)
                    Console.Write(" ");
                //별 출력
                for (int l = 0; l < i + 1; l++)
                    Console.Write("*");
                Console.WriteLine();
            }
        }
     
    }
}
