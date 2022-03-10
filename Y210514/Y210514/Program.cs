using System;

namespace Y210514
{
    class Program
    {
        //private static PoketMon[] StartingPoketmons = new PoketMon[3];

        static void Main(string[] args)
        {
            /*StartingPoketmons[0] = new PoketMon(5, 100, "피카츄");
            StartingPoketmons[1] = new PoketMon(5, 100, "파이리");
            StartingPoketmons[2] = new PoketMon(5, 100, "꼬북이");*/

            //스타팅 포켓몬 선택

            Trainer User;
            //PoketMon startPoketmon;
            int selectNum = 0;

            Console.WriteLine("================================================");
            Console.WriteLine("스타팅 포켓몬을 선택하세요.");
            Console.WriteLine("1. 피카츄");
            Console.WriteLine("2. 파이리");
            Console.WriteLine("3. 꼬북이");
            Console.Write("숫자를 선택하세요 : ");

            while (true)
            {
                selectNum = int.Parse(Console.ReadLine());
                if(selectNum < 1 | selectNum > 3)
                {
                    Console.Write("1~3 중 선택해주세요 : ");
                }
                else
                {
                    break;
                }
            }
            //Console.Write(selectNum);

            switch (selectNum)
            {
                case 1:
                    //startPoketmon = new PoketMon(5, 100, "피카츄");
                    User = new Trainer(new PoketMon(5, 100, "피카츄"));
                    break;
                case 2:
                    //startPoketmon = new PoketMon(5, 100, "파이리");
                    User = new Trainer(new PoketMon(5, 100, "파이리"));
                    break;
                case 3:
                    //startPoketmon = new PoketMon(5, 100, "꼬북이");
                    User = new Trainer(new PoketMon(5, 100, "파이리"));
                    break;
                default:
                    //startPoketmon = new PoketMon(5, 100, "피카츄");
                    User = new Trainer(new PoketMon(5, 100, "파이리"));
                    break;
            }
            Console.WriteLine();
            Console.WriteLine(">> 선택한 포켓몬은 " + User.GetMyStartPoketMon().getName() + 
                ". (HP : " + User.GetMyStartPoketMon().getHP()+")");
            Console.WriteLine();

            //지역별 프리셋 생성
            Area[] areas = new Area[3];
            areas[0] = new Area("지역1",
                new PoketMon(3,120,"모다피"),
                new PoketMon(6, 50, "꼬마돌"),
                new PoketMon(2, 150, "피죤"));
            areas[1] = new Area("지역2",
                new PoketMon(3, 120, "메타몽"),
                new PoketMon(6, 50, "디그다"),
                new PoketMon(2, 150, "이상해씨"));
            areas[2] = new Area("지역3",
                new PoketMon(3, 120, "잉어킹"),
                new PoketMon(6, 50, "별가사리"),
                new PoketMon(2, 150, "고라파덕"));


            //이동 메뉴
            int selectAreaNum = -1;
            while (true)
            {
                Console.WriteLine("================================================");
                Console.WriteLine("지역을 선택해주세요.");
                Console.WriteLine("1. ");
                Console.WriteLine("2. ");
                Console.WriteLine("3. ");
                Console.Write("숫자를 선택하세요 : ");

                while (true)
                {
                    selectAreaNum = int.Parse(Console.ReadLine());
                    if (selectAreaNum < 1 | selectAreaNum > 3)
                    {
                        Console.Write("1~3 중 선택해주세요 : ");
                    }
                    else
                    {
                        break;
                    }
                }
                Console.WriteLine();
                Console.WriteLine(areas[selectAreaNum-1].getAreaName()+"에 입장하였습니다.");

                //포켓몬 조우 반복문
                while (true)
                {
                    int randomPoketmon;
                    Random rand = new Random();
                    randomPoketmon = rand.Next(-1, 2);
                    if (randomPoketmon != -1)    //전투
                    {
                        Console.WriteLine("전투.");





                    }
                    else         //못만남
                        Console.WriteLine("포켓몬을 발견하지 못했습니다.");

                    Console.WriteLine();
                    Console.WriteLine("다음 행동을 선택해주세요.");
                    Console.WriteLine("1. 계속 탐험.");
                    Console.WriteLine("2. 다른 지역으로 가기");
                    int NextNum = -1;

                    while (true)
                    {
                        NextNum = int.Parse(Console.ReadLine());
                        if (NextNum < 1 | NextNum > 2)
                        {
                            Console.Write("1~2 중 선택해주세요 : ");
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (NextNum == 1)
                        continue;
                    else if (NextNum == 2)
                        break;
                }

            }

        }
    }

    class Area
    {
        private String Name;
        private PoketMon[] poketmonPreset = new PoketMon[3];

        public Area(String inName, PoketMon PoketMon0, PoketMon PoketMon1, PoketMon PoketMon2)
        {
            this.Name = inName;
            poketmonPreset[0] = PoketMon0;
            poketmonPreset[1] = PoketMon0;
            poketmonPreset[2] = PoketMon0;
        }

        public PoketMon CreatRandomPoketmon()
        {
            Random random = new Random();
            int index = random.Next(0, 2);
            return poketmonPreset[index];
        }

        public String getAreaName()
        {
            return this.Name;
        }


    }

    class Trainer
    {
        PoketMon MyStartPoketMon;
        PoketMon[] PoketMonInventory = new PoketMon[50];
        int InventoryIndex = -1;

        public Trainer(PoketMon startPoketmon)
        {
            this.MyStartPoketMon = startPoketmon;
        }

        public void Catch()
        {

        }
        public void Throw()
        {

        }

        public PoketMon GetMyStartPoketMon()
        {
            return MyStartPoketMon;
        }
        public PoketMon GetInventoryPoketmon(int index)
        {
            if (this.InventoryIndex > -1)
                return null;
            else
                return PoketMonInventory[index];
        }
    }

    class PoketMon
    {
        private float Atk;
        private float HP;
        private String Name;

        public PoketMon(float inAtk, float inHP, String inName)
        {
            this.Atk = inAtk;
            this.HP = inHP;
            this.Name = inName;
        }

        public void Attack(float atackPoint)
        {

        }
        public void Death()
        {

        }
        public void Display()
        {

        }

        public String getName()
        {
            return this.Name;
        }
        public float getHP()
        {
            return this.HP;
        }
    }

}
