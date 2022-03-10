#pragma once
#include <iostream>
using namespace std;

class C_SingleTon
{
private:
	C_SingleTon()
	{
		cout << "[" << this << "] C_SingleTon()" << endl;
	}
	static C_SingleTon* _instance;
public:

	static C_SingleTon* GetInstance()
	{
		if (!_instance)
		{
			_instance = new C_SingleTon();
		}
		return _instance;
	}
	void ShowMessage()
	{
		cout << "[" << this << "] SingleTone." << endl;
	}
	void Release()
	{
		if (_instance)
		{
			cout << "[" << this << "] Release()" << endl;
			delete(_instance);
			_instance = nullptr;
		}
	}
};