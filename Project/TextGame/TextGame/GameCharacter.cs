using System;
using System.Collections.Generic;
using System.Text;

namespace TextGame
{
    class GameCharacter
    {
        private int level;
        private float money;
        private float hp;
        private float maxHp;
        private float ap;

        //생성자
        public GameCharacter(float defaultMoney, float defaultHP, float defaultAP)
        {
            money = defaultMoney;
            hp = defaultHP;
            maxHp = defaultHP;
            ap = defaultAP;

            level = 1;
        }

        //기능
        public void levelup()
        {
            level += 1;
        }
        public void ShowAll()
        {
            Console.WriteLine("레벨 : " + level.ToString());
            Console.WriteLine("소지금 : " + money.ToString());
            Console.WriteLine("HP : " + hp.ToString() + "/" + maxHp.ToString());
            Console.WriteLine("AP : " + ap.ToString());
        }
        public void Attack(GameCharacter target)
        {
            target.Hit(ap);
        }
        public void Hit(float value)
        {
            hp -= value;
        }
        public bool IsAlive()
        {
            return hp > 0;
        }
    }

    /*class Monster : GameCharacter
    {
        float skillPower;

        //생성자
        public Monster(float defaultMoney, float defaultSkillPower) : base(defaultMoney)
        {
            skillPower = defaultSkillPower;
        }
    }*/
}
