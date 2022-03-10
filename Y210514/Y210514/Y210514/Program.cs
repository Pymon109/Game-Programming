using System;

namespace Y210514
{
    class Program
    {
        static void Main(string[] args)
        {

            //스타팅 포켓몬 선택

            Trainer User;

            Console.WriteLine("================================================");
            Console.WriteLine("바깥은 혼자 돌아다니기엔 위험하단다.");
            Console.WriteLine("이 아이들 중 하나를 데려가렴.");
            Console.WriteLine("1. 피카츄");
            Console.WriteLine("2. 파이리");
            Console.WriteLine("3. 꼬북이");
            Console.Write("숫자를 선택하세요 : ");

            int selectNum = SelectMenu(1, 3);

            switch (selectNum)
            {
                case 1:
                    User = new Trainer(new PoketMon(10, 100, "피카츄"));
                    break;
                case 2:
                    User = new Trainer(new PoketMon(10, 100, "파이리"));
                    break;
                case 3:
                    User = new Trainer(new PoketMon(10, 100, "파이리"));
                    break;
                default:
                    User = new Trainer(new PoketMon(10, 100, "파이리"));
                    break;
            }
            Console.WriteLine();
            Console.WriteLine(">> 선택한 포켓몬은");
            User.GetInventoryPoketmon(0).Display();
            Console.WriteLine();

            //지역별 프리셋 생성
            Area[] areas = new Area[3];
            areas[0] = new Area("숲",
                new PoketMon(3, 120, "모다피"),
                new PoketMon(6, 50, "이상해씨"),
                new PoketMon(2, 150, "피죤"));
            areas[1] = new Area("사막",
                new PoketMon(3, 120, "메타몽"),
                new PoketMon(6, 50, "디그다"),
                new PoketMon(2, 150, "모래두지"));
            areas[2] = new Area("바다",
                new PoketMon(3, 120, "잉어킹"),
                new PoketMon(6, 50, "별가사리"),
                new PoketMon(2, 150, "고라파덕"));

            //이동 메뉴
            while (true)
            {
                Console.WriteLine("================================================");
                Console.WriteLine("지역을 선택해주세요.");
                Console.WriteLine("1. 숲");
                Console.WriteLine("2. 사막");
                Console.WriteLine("3. 바다");
                Console.Write("숫자를 선택하세요 : ");

                int selectAreaNum = SelectMenu(1, 3);

                Console.WriteLine();
                Console.WriteLine(areas[selectAreaNum - 1].getAreaName() + "에 입장하였습니다.");

                //포켓몬 조우 반복문
                while (true)
                {
                    int randomPoketmon;
                    Random rand = new Random();
                    randomPoketmon = rand.Next(-1, 2);
                    if (randomPoketmon != -1)    //몬스터 조우
                    {
                        PoketMon findedPoketmon = areas[selectAreaNum - 1].CreatRandomPoketmon();
                        Console.WriteLine();
                        Console.WriteLine("앗, 야생의 " + findedPoketmon.getName() + "(이)가 나타났다!");

                        Console.WriteLine("싸울까?");
                        Console.WriteLine("1. 싸우다.");
                        Console.WriteLine("2. 도망치다.");
                        Console.Write("숫자를 선택하세요 : ");
                        int fightingNum = SelectMenu(1, 2);

                        if (fightingNum == 1)    //전투 돌입
                        {
                            //Console.WriteLine("전투 시작.");
                            int selectInven = -1;
                            while (true)
                            {
                                Console.WriteLine();
                                Console.WriteLine("================================================");
                                User.DisplayInventory();
                                Console.WriteLine("================================================");
                                Console.Write("싸울 포켓몬을 선택하세요 : ");
                                selectInven = SelectMenu(0, User.getInventoryIndex());
                                Console.WriteLine();

                                if (User.GetInventoryPoketmon(selectInven).Death())
                                    Console.WriteLine("이(가) 포켓몬은 싸울 수 없습니다.");
                                else
                                    break;
                            }

                            while (true)
                            {
                                Console.WriteLine("1. 공격");
                                Console.WriteLine("2. 도망치다.");
                                Console.Write("숫자를 선택하세요 : ");

                                int command = SelectMenu(1, 2);

                                if (command == 2)
                                {
                                    Console.WriteLine();
                                    Console.WriteLine("나는 " + findedPoketmon.getName() + "(으)로부터 도망쳤다.");
                                    break;
                                }
                                else if (command == 1)
                                {
                                    User.GetInventoryPoketmon(selectInven).Attack(findedPoketmon);

                                    if (!findedPoketmon.Death())
                                        findedPoketmon.Attack(User.GetInventoryPoketmon(selectInven));
                                    else
                                    {
                                        
                                        Console.WriteLine(findedPoketmon.getName()+"이(가) 쓰러졌다!");
                                        User.GetInventoryPoketmon(selectInven).gainExp();
                                        Console.WriteLine("몬스터볼을 던지시겠습니까?");
                                        Console.WriteLine("1. 던지다.");
                                        Console.WriteLine("2. 그만두다.");
                                        Console.Write("숫자를 선택하세요 : ");
                                        int CatchNum = SelectMenu(1, 2);

                                        

                                            if (CatchNum == 2)
                                        {
                                            Console.WriteLine(findedPoketmon.getName() + "을(를) 놔줬다.");
                                            break;
                                        }
                                        else if (CatchNum == 1)
                                        {
                                            User.Catch(findedPoketmon);
                                        }

                                        break;
                                    }
                                    if (User.GetInventoryPoketmon(selectInven).Death())
                                    {
                                        Console.WriteLine("내 포켓몬이 쓰러졌다!");
                                        //다른 포켓몬 선택 후 전투 재개
                                        Console.WriteLine();
                                        Console.WriteLine("다른 포켓몬으로 싸우시겠습니까?");
                                        Console.WriteLine("1. 싸우다.");
                                        Console.WriteLine("2. 도망치다.");
                                        Console.Write("숫자를 선택하세요 : ");
                                        int continueComman = SelectMenu(1, 2);
                                        if(continueComman == 2)
                                        {
                                            Console.WriteLine();
                                            Console.WriteLine("나는 " + findedPoketmon.getName() + "(으)로부터 도망쳤다.");
                                            break;
                                        }
                                        else
                                        {
                                            while (true)
                                            {
                                                Console.WriteLine();
                                                Console.WriteLine("================================================");
                                                User.DisplayInventory();
                                                Console.WriteLine("================================================");
                                                Console.Write("싸울 포켓몬을 선택하세요 : ");
                                                selectInven = SelectMenu(0, User.getInventoryIndex());
                                                Console.WriteLine();

                                                if (User.GetInventoryPoketmon(selectInven).Death())
                                                    Console.WriteLine("이 포켓몬은 싸울 수 없습니다.");
                                                else
                                                    break;
                                            }
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        else     //도망
                        {
                            Console.WriteLine();
                            Console.WriteLine("나는 " + findedPoketmon.getName() + "(으)로부터 도망쳤다.");
                        }

                    }
                    else         //못만남
                    {
                        Console.WriteLine();
                        Console.WriteLine("포켓몬을 발견하지 못했습니다.");
                    }
                    Console.WriteLine();
                    Console.WriteLine("다음 행동을 선택해주세요.");
                    Console.WriteLine("1. 계속 탐험.");
                    Console.WriteLine("2. 다른 지역으로 가기");
                    Console.Write("숫자를 선택하세요 : ");
                    int NextNum = SelectMenu(1, 2);

                    if (NextNum == 1)
                        continue;
                    else if (NextNum == 2)
                        break;
                }

            }

        }

        static int SelectMenu(int minNum, int maxNum)
        {
            int selectNum = -1;
            while (true)
            {
                selectNum = int.Parse(Console.ReadLine());
                if (selectNum < minNum | selectNum > maxNum)
                {
                    Console.Write(minNum + "~" + maxNum + " 중 선택해주세요 : ");
                }
                else
                {
                    return selectNum;
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
            poketmonPreset[1] = PoketMon1;
            poketmonPreset[2] = PoketMon2;
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
        //public PoketMon MyStartPoketMon;
        private PoketMon[] PoketMonInventory = new PoketMon[50];
        int InventoryIndex = -1;

        public Trainer(PoketMon startPoketmon)
        {
            this.PoketMonInventory[0] = startPoketmon;
            InventoryIndex = 0;
        }

        public void Catch(PoketMon target)
        {
            Random rand = new Random();
            target.setMaxHP();

            while (true)
            {
                int randCatch = rand.Next(1, 10);
                int randRun = rand.Next(1, 10);
                if (randCatch > 7)
                {
                    this.PoketMonInventory[++this.InventoryIndex] = target;
                    Console.WriteLine(target.getName() + "를 잡았다!");
                    return ;
                }
                else
                {
                    Console.WriteLine(target.getName() + "몬스터 볼이 빗나갔다!");
                    if (randRun < 3)
                    {
                        Console.WriteLine(target.getName() + "를 놓쳤다!");
                        return;
                    }
                    else
                        continue;
                }
            }
            
        }
        public void Throw() //? ㅋㅋ
        {

        }

        public PoketMon GetInventoryPoketmon(int index)
        {
            if (this.InventoryIndex < -1)
                return null;
            else
                return PoketMonInventory[index];
        }
        public void DisplayInventory()
        {
            Console.WriteLine("인벤토리 현황[" + (InventoryIndex + 1) + "/50]");
            if (InventoryIndex > -1)
            {
                for (int i = 0; i <= this.InventoryIndex; i++)
                {
                    Console.WriteLine(i + ".");
                    PoketMonInventory[i].Display();
                }
            }
        }
        public int getInventoryIndex()
        {
            return this.InventoryIndex;
        }
    }

    class PoketMon
    {
        private float MaxExp;
        private float CurrentExp;
        private int Level;
        private float Atk;
        private float HP;
        private float MaxHP;
        private String Name;

        public PoketMon(float inAtk, float inHP, String inName)
        {
            this.Level = 1;
            this.CurrentExp = 0;
            this.MaxExp = 100;
            this.Atk = inAtk;
            this.HP = inHP;
            this.MaxHP = inHP;
            this.Name = inName;
        }

        public void Attack(PoketMon target)
        {
            Console.WriteLine(this.Name + "의 몸통 박치기!");
            target.Hit(this.Atk+ this.Atk*((this.Level-1)*0.1f));
        }
        public void Hit(float value)
        {
            this.HP -= value;
            Console.WriteLine(this.Name + "의 HP가 " + value + "만큼 줄어들었다. (현재 HP : "
                + this.HP + ")");
        }
        public bool Death()
        {
            return HP <= 0;
        }
        public void Display()
        {
            Console.WriteLine("이름 : " + this.Name);
            Console.WriteLine("레벨 : " + this.Level);
            Console.WriteLine("경험치 : " + this.CurrentExp);
            Console.WriteLine("공격력 : " + this.Atk + this.Atk * ((this.Level - 1) * 0.1f));
            Console.WriteLine("생명력 : " + this.HP);
        }
        public void gainExp()
        {
            this.CurrentExp += 50;
            if (this.CurrentExp >= 100)
            {
                ++this.Level;
                this.CurrentExp -= 100;
                Console.WriteLine(this.Name + "의 레벨이 올라 " + this.Level + "이 되었습니다.");
            }
               
        }

        public String getName()
        {
            return this.Name;
        }
        public float getHP()
        {
            return this.HP;
        }
        public void setMaxHP()
        {
            this.HP = this.MaxHP;
        }
    }

}
