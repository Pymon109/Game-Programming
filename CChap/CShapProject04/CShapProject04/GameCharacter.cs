using System;
using System.Collections.Generic;
using System.Text;

namespace CShapProject04
{
    class GameCharacter
    {
        private int level;
        private float money;

        //기능
        public void levelup()
        {
            level += 1;
        }
        public void ShowAll()
        {
            Console.WriteLine("레벨 : " + level.ToString());
            Console.WriteLine("소지금 : " + money.ToString());
        }

        //생성자
        public GameCharacter(float defaultMoney)
        {
            money = defaultMoney;
            level = 1;
        }
    }

    class Monster : GameCharacter
    {
        float skillPower;
        public Monster(float defaultMoney,float defaultSkillPower) : base(defaultMoney)
        {
            skillPower = defaultSkillPower;
        }
    }
}
