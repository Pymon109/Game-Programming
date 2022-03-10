#include "textRPG.h"													


using namespace std;

C_Player player = C_Player(C_Status(), C_Stature(), "player", E_CLASS::WORRIOR);
C_Inventory inventory = C_Inventory();

void Battle(C_Monster target)
{
	cout << "몬스터 출현!" << endl;
	target.ShowCharacterInfo();
	enum E_COMMAND
	{
		//공격 / 회복 / 도망가기												
		RUN = 0,
		ATTACK,
		INVENTORY
	};
	int inputKey;
	bool continueTrigger = true;
	while (continueTrigger)
	{
		cout << "battle >> 0. 도망가기 1. 공격 2. 회복" << endl;
		cout << "input command : ";
		cin >> inputKey;
		switch (inputKey)
		{
		case RUN:
			cout << "몬스터로부터 도망쳤다." << endl;
			continueTrigger = false;
			break;
		case ATTACK:
			if (!player.Attack(target))
			{
				if (target.GetRewardItem() != NULL)
				{
					cout << target.GetRewardItem()->GetName() << "을(를) 얻었다." << endl;
					inventory.AddItem(*target.GetRewardItem());
					inventory.ShowInventory();
				}
				continueTrigger = false;
				break;
			}
			else if (!target.Attack(player))
			{
				continueTrigger = false;
				break;
			}
			break;
		case INVENTORY:
			//player.RecoveryHP(5);
			inventory.ShowInventory();
			//인벤 사용하기
			if (!target.Attack(player))
			{
				continueTrigger = false;
				break;
			}
			break;
		default:
			cout << "error : out of range (input)" << endl;
			break;
		}
	}
}

void Inventory()
{
	inventory.ShowInventory();

}

void TextGameMain()
{
	C_Monster monster = C_Monster(C_Status(2, 5, 25, 999), C_Stature(1, 30), "slime",
		new C_Equipment("낡은 검", 100, C_Status(2, 0, 0, 0), C_Equipment::E_EQUIP_TYPE::WEAPON,
			E_CLASS::ALL, 10), 100);

	player.ShowCharacterInfo();
	//Battle(monster);
	Inventory();
}

void main()
{
	TextGameMain();
}