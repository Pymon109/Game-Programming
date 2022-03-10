#pragma once

#include <iostream>
#include <List>

using namespace std;

class Unit
{
protected:
	int _hp;
	int _pos_x;
	int _pos_y;

	void Death()
	{
		cout << "[" << this << "] unit Death." << endl;
		this->~Unit();
	}
public:
	Unit(int hp = 100)
	{
		_hp = hp;
		_pos_x = 0;
		_pos_y = 0;

		cout << "[" << this << "] Unit()" << endl;
	}
	~Unit()
	{
		cout << "[" << this << "] ~Unit()" << endl;
	}
	void Hit(int dmg)
	{
		cout << "[" << this << "] unit Hit (HP : " << _hp << ")" << endl;
		_hp -= dmg;
		if (_hp <= 0)
			Death();
	}
	void Recovery(int heal)
	{
		cout << "[" << this << "] unit Recovery HP "<< _hp << "(+" << heal <<")" << endl;
	}
	virtual void Move(int x, int y) = 0 { }
	virtual void Attack(Unit* target)  = 0{ }
	virtual void Heal(Unit* target) = 0 { }
};

class Marin : public Unit
{
private:
	int _atk;
public:
	Marin(int hp = 100, int atk = 10)
	{
		_hp = hp;
		_pos_x = 0;
		_pos_y = 0;

		_atk = atk;

		cout << "[" << this << "] Marin()" << endl;
	}
	~Marin()
	{
		cout << "[" << this << "] ~Marin()" << endl;
	}
	void Move(int x, int y) override
	{
		cout << "[" << this << "] Marin Move to (" << x << "," << y << ")" << endl;
	}
	void Attack(Unit* target) override
	{
		cout << "[" << this << "] Marin Attack [" << target << "] (dmg : " <<_atk << ")" << endl;
		target->Hit(_atk);
	}
	void Heal(Unit* target) override
	{

	}
};

class Medic : public Unit
{
private:
	int _healing;
public:
	Medic(int hp = 100, int healing = 30)
	{
		_hp = hp;
		_pos_x = 0;
		_pos_y = 0;

		_healing = healing;

		cout << "[" << this << "] Medic()" << endl;
	}
	~Medic()
	{
		cout << "[" << this << "] ~Medic()" << endl;
	}
	void Move(int x, int y) override
	{
		cout << "[" << this << "] Medic Move to (" << x << "," << y << ")" << endl;
	}
	void Attack(Unit* target) override
	{

	}
	void Heal(Unit* target) override
	{
		cout << "[" << this << "] Medic Heal [" << target << "]" << endl;
		target->Recovery(_healing);
	}
};

class Commander
{
private:
	list<Unit*> _unitCollection;
	list<Unit*>::iterator iter;
public:
	Commander()
	{
		_unitCollection = list<Unit*>();
		cout << "[" << this << "] Commander()" << endl;
	}
	void SelecUnit(Unit* unit)
	{
		_unitCollection.push_back(unit);
	}
	void DeselectUnit(Unit* unit)
	{
		_unitCollection.remove(unit);
	}
	void Move(int x, int y)
	{
		for (iter = _unitCollection.begin(); iter != _unitCollection.end(); iter++)
		{
			(*iter)->Move(x, y);
		}
	}
	void Attack(Unit* target)
	{
		for (iter = _unitCollection.begin(); iter != _unitCollection.end(); iter++)
		{
			(*iter)->Attack(target);
		}
	}
	void Heal(Unit* target)
	{
		for (iter = _unitCollection.begin(); iter != _unitCollection.end(); iter++)
		{
			(*iter)->Heal(target);
		}
	}
};