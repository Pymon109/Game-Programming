#include "Game.h"													


using namespace std;

C_Player player = C_Player(C_Status(), C_Stature(), "player", E_CLASS::WORRIOR);

void Battle(C_Monster target);
bool Inventory();

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
		cout << "battle >> 0. 도망가기 1. 공격 2. 인벤토리" << endl;
		cout << "input command : ";
		cin >> inputKey;
		switch (inputKey)
		{
		case RUN:
			cout << "몬스터로부터 도망쳤다." << endl;
			continueTrigger = false;
			break;
		case ATTACK:
			if (!player.Attack(&target))
			{
				continueTrigger = false;
				break;
			}
			else if(!target.Attack(&player))
			{
				continueTrigger = false;
				break;
			}
			break;
		case INVENTORY:
			//player.RecoveryHP(5);
			//inventory.ShowInventory();
			//인벤 사용하기
			while (!Inventory());
			if (!target.Attack(&player))
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

bool Inventory()
{
	int select = -1;
	player.ShowInventory();
	cout << "아이템 선택 : ";
	cin >> select;
	C_Item* s_item = player.SelectItem(select);
	if (!s_item)
	{
		cout << "error : out of range (input)" << endl;
		return false;
	}
	s_item->ShowInfo();
	C_Item::E_ITEM_TYPE type = s_item->GetItemType();
	switch (type)
	{
	case C_Item::EQUIPMENT:
		if (((C_Equipment*)s_item)->IsEpuipped())
		{
			int command = -1;
			cout << "1. 장착 해제  2. 버리기" << endl;
			cout << "입력 : ";
			cin >> command;
			switch (command)
			{
			case 1:
				((C_Equipment*)s_item)->Disequip();
				return true;
			case 2:
				player.ThrowItem(select);
				return true;
			default:
				cout << "error : out of range (input)" << endl;
				return false;
			}
		}
		else
		{
			int command = -1;
			cout << "1. 장착  2. 버리기" << endl;
			cout << "입력 : ";
			cin >> command;
			switch (command)
			{
			case 1:
				((C_Equipment*)s_item)->Equip();
				return true;
			case 2:
				player.ThrowItem(select);
				return true;
			default:
				cout << "error : out of range (input)" << endl;
				return false;
			}
		}
		break;

	case C_Item::EXPENDABLE:
		C_Expendable::E_EXPENDABLE_TYPE expendabelType = ((C_Expendable*)s_item)->GetExpendabelType();
		switch (expendabelType)
		{
		case C_Expendable::HP:
			((C_RecoveryHPItem*)s_item)->Use(&player);
			return true;
			break;
		case C_Expendable::MP:
			break;
		case C_Expendable::BEEFUP_ATK:
			break;
		case C_Expendable::BEEFUP_DEF:
			break;
		case C_Expendable::NONE:
			break;
		default:
			break;
		}
		break;
	}
}

void TextGameMain()
{
	C_Monster monster = C_Monster(C_Status(2, 5, 25, 999), C_Stature(1, 30), "slime",
		new C_Equipment("낡은 검",100,C_Status(2,0,0,0),/*C_Stature(0,0),*/C_Equipment::E_EQUIP_TYPE::WEAPON,
			E_CLASS::ALL,10), 100);

	player.Additem(new C_Equipment("낡은 검", 100, C_Status(2, 0, 0, 0),C_Equipment::E_EQUIP_TYPE::WEAPON,
		E_CLASS::ALL, 10));
	player.Additem(new C_RecoveryHPItem("미량의 체력 회복약",10,10));

	player.ShowCharacterInfo();
	Battle(monster);
	//while (!Inventory());
}

void main()
{
	TextGameMain();
}