#pragma once																																														
#include <iostream>																																														
#include <string>																																														
#include <list>																																														
#include <vector>

using namespace std;

enum E_CLASS
{
	WORRIOR = 0,
	SORCERER,
	ASSASSIN,
	PRIEST,
	ALL = -1
};


class C_Item
{
public:
	enum E_ITEM_TYPE
	{
		EQUIPMENT = 0,
		EXPENDABLE,
		BOOTY,

		NONE = -1
	};
protected:
	string _name;
	int _price;
	bool _userable;
	E_ITEM_TYPE _item_type;
public:
	C_Item(string name = "unknown", int price = 0)
	{
		_name = name;
		_price = price;
		_userable = false;
		_item_type = E_ITEM_TYPE::NONE;
	}

	string GetName() { return _name; }
	E_ITEM_TYPE GetItemType() { return _item_type; }

	virtual void ShowInfo() { }
};

class C_Status
{
private:
	float _ATK_basic;
	float _DEF_basic;
	float _maxHP_basic;
	float _maxMP_basic;

	float _ATK_equipment;
	float _DEF_equipment;
	float _HP_equipment;
	float _MP_equipment;

	float _ATK_coeff;
	float _DEF_coeff;

	float _currentHP;
	float _currentMP;

public:
	C_Status(float atk = 10, float def = 10, float hp = 50, float mp = 50)
	{
		_ATK_basic = atk;
		_DEF_basic = def;
		_maxHP_basic = hp;
		_maxMP_basic = mp;

		_ATK_equipment = 0;
		_DEF_equipment = 0;
		_HP_equipment = 0;
		_MP_equipment = 0;

		_ATK_coeff = 1.5;
		_DEF_coeff = 1.5;
		_currentHP = hp;
		_currentMP = mp;
	}
	float GetBasicATK() { return _ATK_basic; }
	float GetBasicDEF() { return _DEF_basic; }
	float GetMaxHP() { return _maxHP_basic; }
	float GetMaxMP() { return _maxMP_basic; }
	float GetEquipATK() { return _ATK_equipment; }
	float SetEquipATK(float atk) { _ATK_equipment += atk; }
	float GetEquipDEF() { return _DEF_equipment; }
	float SetEquipDEF(float def) { _DEF_equipment += def; }
	float GetCoeffATK() { return _ATK_coeff; }
	float GetCoeffDEF() { return _DEF_coeff; }
	bool ReduceHP(float dmg)
	{
		_currentHP -= dmg;
		cout << "HP : " << _currentHP << "(-" << dmg << ")/" << _maxHP_basic << endl;
		if (_currentHP <= 0)
			return false;
		else
			return true;
	}
	bool ConsumeMP(int consumption)
	{
		if (_currentMP >= consumption)
		{
			_currentMP -= consumption;
			return true;
		}
		else
			return false;
	}
	void GainHP(int hp)
	{
		_currentHP += hp;
		if (_currentHP > _maxHP_basic)
			_currentHP = _maxHP_basic;
		cout << "HP : " << _currentHP << "(+" << hp << ")/" << _maxHP_basic << endl;
	}
	void GainMP(int mp)
	{
		_currentHP += mp;
		if (_currentMP > _maxMP_basic)
			_currentMP = _maxMP_basic;
		cout << "HP : " << _currentHP << "(+" << mp << ")/" << _maxHP_basic << endl;
	}
	void showStatus()
	{
		cout << "ATK : " << _ATK_basic + _ATK_equipment << endl;
		cout << "DEF : " << _DEF_basic + _DEF_equipment << endl;
		cout << "HP : " << _currentHP << "/" << _maxHP_basic << endl;
		cout << "MP : " << _currentMP << "/" << _maxMP_basic << endl;
	}
};

class C_Equipment : public C_Item
{
public:
	enum E_EQUIP_TYPE
	{
		WEAPON = 0,
		ARMOR,

		NONE = -1
	};
private:
	E_EQUIP_TYPE _equip_type;
	C_Status _status;
	//C_Stature _stature;
	E_CLASS _class;
	int _maxDurability;
	int _currentDurability;
	bool _isEquipped;
public:
	C_Equipment(string name = "unknown", int price = 0, C_Status status = C_Status(0, 0, 0, 0), /*C_Stature stature = C_Stature(0, 0),*/
		E_EQUIP_TYPE type = E_EQUIP_TYPE::NONE, E_CLASS Eclass = E_CLASS::ALL, int durability = 1)
	{
		_name = name;
		_price = price;
		_userable = false;
		_status = status;
		//_stature = stature;
		_equip_type = type;
		_class = Eclass;
		_maxDurability = durability;
		_currentDurability = durability;
		_isEquipped = false;

		_item_type = E_ITEM_TYPE::EQUIPMENT;
	}
	C_Status GetEquipStatus() { return _status; }
	E_EQUIP_TYPE GetType() { return _equip_type; }
	void ShowInfo() override
	{
		cout << "아이템 이름 : " << _name << endl;
		string s_class = "";
		switch (_class)
		{
		case WORRIOR:
			s_class = "전사";
			break;
		case SORCERER:
			s_class = "마법사";
			break;
		case ASSASSIN:
			s_class = "암살자";
			break;
		case PRIEST:
			s_class = "사제";
			break;
		case ALL:
			s_class = "전체";
			break;
		default:
			break;
		}
		cout << "착용 클래스 : " << s_class << endl;
		cout << "내구도 (" << _currentDurability << "/" << _maxDurability << ")" << endl;
		cout << "가격 : " << _price << endl;
		cout << "장비 공격력 : " << _status.GetBasicATK() << endl;
		cout << "장비 방어력 : " << _status.GetBasicDEF() << endl;
		cout << "최대 HP : " << _status.GetMaxHP() << endl;
		cout << "최대 MP : " << _status.GetMaxHP() << endl;
	}
	bool IsEpuipped() { return _isEquipped; }
	void Equip()
	{
		_isEquipped = true;

		cout << _name << "을(를) 장착 하였습니다." << endl;
	}
	void Disequip()
	{
		_isEquipped = false;

		cout << _name << "을(를) 해제 하였습니다." << endl;
	}
};


class C_Stature
{
private:
	float _EXP;
	int _LV;
public:
	C_Stature(int lv = 1, float exp = 0)
	{
		_LV = lv;
		_EXP = exp;
	}
	int GetLv() { return _LV; }
	float GetEXP() { return _EXP; }
	bool IncreseEXP(float exp)
	{
		_EXP += exp;
		if (_EXP >= 100 + (_LV * 10))
			return true;
		else
			return false;
	}
	void LevelUp(C_Status status)
	{
		_EXP -= 100 + (_LV * 10);
		_LV++;
		//status.SetCoeffByLevelUp();																																												
	}
	void ShowStature()
	{
		cout << "Level : " << _LV << endl;
		cout << "EXP : " << _EXP << "/" << 100 + (_LV * 10) << endl;
	}
};



class C_Character
{
protected:
	C_Status _status;
	C_Stature _stature;
	string _name;

	virtual void Death()
	{
		cout << "[" << _name << "] dies." << endl;
	}
public:
	C_Character(C_Status status = C_Status(), C_Stature stature = C_Stature(), string name = "unknown")
	{
		_status = status;
		_stature = stature;
		_name = name;
	}
	virtual bool Hit(float dmg)
	{
		float def_per = (_status.GetBasicDEF() + _status.GetEquipDEF()) / (_status.GetBasicDEF() + _status.GetEquipDEF() +
			(_status.GetCoeffDEF() * _stature.GetLv()));
		float dmg_fin = dmg * (1 - def_per);
		cout << "[" << _name << "] defend and take " << dmg_fin << " damage. ";
		if (!_status.ReduceHP(dmg_fin))
		{
			Death();
			return false;
		}
		else
			return true;
	}
	virtual bool Attack(C_Character *target)
	{
		float dmg = _status.GetBasicATK() + _status.GetEquipATK() + (_status.GetCoeffATK() * _stature.GetLv());
		cout << "[" << _name << "]attack [" << target->_name << "] (dmg :" << dmg << ")." << endl;
		if (!target->Hit(dmg))
		{
			return false;
		}
		else
			return true;
	}
	virtual void RecoveryHP(int hp)
	{
		cout << "[" << _name << "] recovered by  " << hp << ".";
		_status.GainHP(hp);
	}
	virtual void ShowCharacterInfo()
	{
		cout << "[" << _name << "]' Info ############################" << endl;
		cout << "<stature>" << endl;
		_stature.ShowStature();
		cout << "<status>" << endl;
		_status.showStatus();
	}

	string GetName() { return _name; }
	float GetEXP() { return _stature.GetEXP(); }

	virtual void GainItem(C_Item item) { }
	virtual C_Item* GetRewardItem() { return NULL; }
	virtual int GetRewardGold() { return 0; }
};

class C_Inventory
{
private:
	vector<C_Item*> _v_storage;
	int _maxSize;
public:
	C_Inventory(int size = 50)
	{
		_v_storage = vector<C_Item*>();
		_maxSize = size;
	}
	bool AddItem(C_Item* item)
	{
		if (_v_storage.size() >= _maxSize)
			return false;
		else
		{
			_v_storage.push_back(item);
			return true;
		}
	}
	void DeleteItem(int idx)
	{
		vector< C_Item*>::iterator i = _v_storage.begin() + idx;
		_v_storage.erase(i);
	}
	void ShowInventory()
	{
		cout << "################################" << endl;
		for (int i = 0; i < _v_storage.size(); i++)
		{
			cout << i << ". " << _v_storage[i]->GetName() << endl;
		}
		cout << "################################" << endl;
	}
	C_Item* SelectItem(int index)
	{
		if (IsEmpy())
		{
			cout << "Inventory Is Empty." << endl;
			return NULL;
		}
		if (index <= _v_storage.size() - 1)
		{
			return _v_storage[index];
		}
		else
		{
			cout << "error : inventory index exceeded." << endl;
			return NULL;
		}
	}
	bool IsEmpy() { return _v_storage.size() < 1; }
};


class C_Player : public C_Character
{
private:
	E_CLASS _class;
	C_Inventory _inventory;
	C_Equipment* _weapon;
	C_Equipment* _armor;
public:
	C_Player(C_Status status = C_Status(), C_Stature stature = C_Stature(), string name = "unknown",
		E_CLASS Eclass = E_CLASS::ALL)
	{
		_status = status;
		_stature = stature;
		_name = name;
		_class = Eclass;
		_inventory = C_Inventory();
	}
	bool Attack(C_Character* target) override
	{
		//C_Monster m_target = (C_Monster)target;
		float dmg = _status.GetBasicATK() + _status.GetEquipATK() + (_status.GetCoeffATK() * _stature.GetLv());
		cout << "[" << _name << "]attack [" << target->GetName() << "] (dmg :" << dmg << ")." << endl;
		if (!target->Hit(dmg))
		{
			//Exp 얻기																																											
			cout << "[" << _name << "] get " << target->GetEXP() << " exp." << endl;
			if (_stature.IncreseEXP(target->GetEXP()))
			{
				_stature.LevelUp(_status);
				cout << "[" << _name << "] level up to " << _stature.GetLv() << endl;
			}
			//아이템 얻기
			cout << "[" << _name << "] get itme : " << target->GetRewardItem()->GetName() << "." << endl;
			_inventory.AddItem(target->GetRewardItem());
			_inventory.ShowInventory();
			return false;
		}
		else
			return true;
	}
	void EquipeWeapon(C_Equipment* weapon)
	{
		if (weapon->GetType() == C_Equipment::E_EQUIP_TYPE::WEAPON)
		{
			_status.SetEquipATK(_weapon->GetEquipStatus().GetBasicATK() * -1);
			_status.SetEquipDEF(_weapon->GetEquipStatus().GetBasicDEF() * -1);
			_weapon = weapon;
			_status.SetEquipATK(_weapon->GetEquipStatus().GetBasicATK());
			_status.SetEquipDEF(_weapon->GetEquipStatus().GetBasicDEF());
		}
		else
			cout << "error : equipment type matching" << endl;
	}
	void EquipeAmor(C_Equipment* armor)
	{
		if (armor->GetType() == C_Equipment::E_EQUIP_TYPE::ARMOR)
		{
			_status.SetEquipATK(_armor->GetEquipStatus().GetBasicATK() * -1);
			_status.SetEquipDEF(_armor->GetEquipStatus().GetBasicDEF() * -1);
			_armor = armor;
			_status.SetEquipATK(_armor->GetEquipStatus().GetBasicATK());
			_status.SetEquipDEF(_armor->GetEquipStatus().GetBasicDEF());
		}
		else
			cout << "error : equipment type matching" << endl;
	}
	void ShowInventory() { _inventory.ShowInventory(); }
	void Additem(C_Item* item) { _inventory.AddItem(item); }
	C_Item* SelectItem(int index) { return _inventory.SelectItem(index); }
	void ThrowItem(int index)
	{
		cout << _inventory.SelectItem(index)->GetName() << "을(를) 버렸습니다." << endl;
		_inventory.DeleteItem(index);
	}
};

class C_Monster : public C_Character
{
private:
	C_Item* _rewardItem;
	int _rewardGold;
public:
	C_Monster(C_Status status = C_Status(), C_Stature stature = C_Stature(), string name = "unknown",
		C_Item* rewardItem = NULL, int rewardGold = 0)
	{
		_status = status;
		_stature = stature;
		_name = name;
		_rewardItem = rewardItem;
		_rewardGold = rewardGold;
	}
	C_Item* GetRewardItem() override { return this->_rewardItem; }
	int GetRewardGold() override { return _rewardGold; }
};

class C_Expendable : public C_Item
{
public:
	enum E_EXPENDABLE_TYPE
	{
		HP = 0,
		MP,
		BEEFUP_ATK,
		BEEFUP_DEF,

		NONE = -1
	};
protected:
	E_EXPENDABLE_TYPE _expendabel_type;
public:
	virtual void Use(C_Player* player) = 0 {}
	E_EXPENDABLE_TYPE GetExpendabelType() { return _expendabel_type; }
};

class C_RecoveryHPItem : public C_Expendable
{
private:
	float _amontOfRecovery;
public:
	C_RecoveryHPItem(string name = "unknown", int price = 0, float recovery = 10)
	{
		_name = name;
		_price = price;
		_userable = false;
		_amontOfRecovery = recovery;

		_item_type = E_ITEM_TYPE::EXPENDABLE;
		_expendabel_type = E_EXPENDABLE_TYPE::HP;
	}
	void Use(C_Player* player) override
	{
		player->RecoveryHP(_amontOfRecovery);
	}
};