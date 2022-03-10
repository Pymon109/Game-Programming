#include "Game.h"													


using namespace std;

C_Player player = C_Player(C_Status(), C_Stature(), "player", E_CLASS::WORRIOR);

void Battle(C_Monster target);
bool Inventory();

void Battle(C_Monster target)
{
	cout << "���� ����!" << endl;
	target.ShowCharacterInfo();
	enum E_COMMAND
	{
		//���� / ȸ�� / ��������												
		RUN = 0,
		ATTACK,
		INVENTORY
	};
	int inputKey;
	bool continueTrigger = true;
	while (continueTrigger)
	{
		cout << "battle >> 0. �������� 1. ���� 2. �κ��丮" << endl;
		cout << "input command : ";
		cin >> inputKey;
		switch (inputKey)
		{
		case RUN:
			cout << "���ͷκ��� �����ƴ�." << endl;
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
			//�κ� ����ϱ�
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
	cout << "������ ���� : ";
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
			cout << "1. ���� ����  2. ������" << endl;
			cout << "�Է� : ";
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
			cout << "1. ����  2. ������" << endl;
			cout << "�Է� : ";
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
		new C_Equipment("���� ��",100,C_Status(2,0,0,0),/*C_Stature(0,0),*/C_Equipment::E_EQUIP_TYPE::WEAPON,
			E_CLASS::ALL,10), 100);

	player.Additem(new C_Equipment("���� ��", 100, C_Status(2, 0, 0, 0),C_Equipment::E_EQUIP_TYPE::WEAPON,
		E_CLASS::ALL, 10));
	player.Additem(new C_RecoveryHPItem("�̷��� ü�� ȸ����",10,10));

	player.ShowCharacterInfo();
	Battle(monster);
	//while (!Inventory());
}

void main()
{
	TextGameMain();
}