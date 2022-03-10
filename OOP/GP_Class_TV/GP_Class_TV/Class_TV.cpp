#include <conio.h>
#include<iostream>							
#include<string>
#include <queue>

using namespace std;

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_SPACE 32

class C_TV
{
public:
	enum E_line_id
	{
		NORMAL = 0,
		RARE,
		UNIQUE
	};
	enum E_shape
	{
		STAND = 0,
		WALL
	};

private:
	int _sid;
	E_line_id _lid;
	E_shape _shape;

	bool _power;
	int _channel;
	int _volume;

public:
	C_TV(int sid, E_line_id lid, E_shape shape)
	{
		_sid = sid;
		_lid = lid;
		_shape = shape;

		_power = false;
		_channel = 999;
		_volume = 15;
	}
	C_TV()
	{
		_sid = 0;
		_lid = E_line_id::NORMAL;
		_shape = E_shape::STAND;

		_power = false;
		_channel = 999;
		_volume = 15;
	}

	void ShowInfo()
	{
		cout << "=============================TV Info" << endl;
		cout << "��ǰ �ѹ� : " << _sid << endl;
		switch (_lid)
		{
		case C_TV::NORMAL:
			cout << "�Ϲ� ����" << endl;
			break;
		case C_TV::RARE:
			cout << "��� ����" << endl;
			break;
		case C_TV::UNIQUE:
			cout << "�ְ�� ����" << endl;
			break;
		default:
			break;
		}
		switch (_shape)
		{
		case C_TV::STAND:
			cout << "���ĵ��� Ƽ��" << endl;
			break;
		case C_TV::WALL:
			cout << "�������� Ƽ��" << endl;
			break;
		default:
			break;
		}
		cout << "====================================" << endl;
	}

	E_line_id GetLID() { return _lid; }

	//���� ����						
	void Power()
	{
		_power = !_power;
	}

	//ä�� ����						
	int GetChannel()
	{
		if (_power)
		{
			//cout << "[" << _sid << "] ���� ä�� : " << _channel << endl;
			return _channel;
		}
		return -1;
	}
	void ChannelUp()
	{
		if (_power)
		{
			_channel++;
			//cout << "[" << _sid << "] [ChannelUp] ���� ä�� : " << _channel << endl;
		}
	}
	void ChannelDown()
	{
		if (_power)
		{
			_channel--;
			//cout << "[" << _sid << "] [ChannelDown] ���� ä�� : " << _channel << endl;
		}
	}
	void SetChannel(int input)
	{
		if (_power)
		{
			_channel = input;
			//cout << "[" << _sid << "] [SetChannel] ���� ä�� : " << _channel << endl;
		}
	}

	//���� ����						
	void VolumeUp()
	{
		if (_power)
		{
			_volume++;
			//cout << "[" << _sid << "] [VolumUp] ���� ���� : " << _volume << endl;
		}
	}
	void VolumeDown()
	{
		if (_power)
		{
			_volume--;
			//cout << "[" << _sid << "] [VolumDown] ���� ���� : " << _volume << endl;
		}
	}

	//Ƽ�� ���� �����ֱ�						
	void ShowTVState()
	{
		if (_power)
		{
			cout << "[" << _sid << "] ȭ�� ������..." << endl;
			cout << "[" << _sid << "] ���� ä�� : " << _channel << endl;
			cout << "[" << _sid << "] ���� : " << _volume << endl;
		}
		else
			cout << "[" << _sid << "] ������ ����" << endl;
	}
};

class C_SIDManager
{
private:
	int _maxSID[3] = { 0, };
public:
	int MakeMaxID(C_TV::E_line_id LID)
	{
		return ++_maxSID[LID];
	}
};

class C_Store
{
private:
	C_TV _showDesk[3];
	queue<C_TV> _storage[3];
	C_SIDManager _sidManager;
public:
	C_Store()
	{
		for (int i = 0; i < 3; i++)
		{
			C_TV* deskTemp = new C_TV(_sidManager.MakeMaxID((C_TV::E_line_id)i),
				(C_TV::E_line_id)i, (C_TV::E_shape)(i % 2));
			_showDesk[i] = *deskTemp;
			for (int j = 0; j < 10; j++)
			{
				C_TV* temp = new C_TV(_sidManager.MakeMaxID((C_TV::E_line_id)i),
					(C_TV::E_line_id)i, (C_TV::E_shape)(i % 2));
				StoreTV(temp);
			}
		}
		//ShowStorageState();
	}

	//showDesk�� ���� �Լ�
	void ShowDeskInfo()
	{
		cout << "=============================�Ŵ�" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "[" << i << "] �� ��ǰ" << endl;
			_showDesk[i].ShowInfo();
		}
	}
	
	//storage�� ���� �Լ�
	void StoreTV(C_TV* tv)
	{
		C_TV::E_line_id LID = tv->GetLID();
		_storage[LID].push(*tv);
	}

	bool CheckStock(C_TV::E_line_id LID)
	{
		bool stoke = !_storage[LID].empty();
		if (!stoke)
			cout << "��� �����ϴ�." << endl;
		return stoke;
	}

	C_TV TakeOut(int number)
	{
		C_TV* tv = NULL;
		C_TV::E_line_id LID = _showDesk[number].GetLID();
		if (CheckStock(LID))
		{
			tv = new C_TV(_storage[LID].front());
			_storage[LID].pop();
		}
		return *tv;
	}

	void ShowStorageState()
	{
		cout << "=============================â�� ���緮" << endl;
		cout << "�Ϲ� ���� : " << _storage[C_TV::E_line_id::NORMAL].size() << "��" << endl;
		cout << "��� ���� : " << _storage[C_TV::E_line_id::RARE].size() << "��" << endl;
		cout << "�ְ�� ���� : " << _storage[C_TV::E_line_id::UNIQUE].size() << "��" << endl << endl;
	}
	
	
};

class C_LivingRoom
{
private:
	C_TV _myTV;
	bool _isHaveTV = false;
public:
	void  OperateMyTV()
	{
		if (!_isHaveTV)
		{
			cout << "������ TV�� �����ϴ�." << endl;
			return;
		}

		enum E_Command
		{
			POWER = 0,
			CHANNERL_UP,
			CHANNERL_DOWN,
			CHANNEL_SET,
			VOLUME_UP,
			VOLUME_DOWN,
			SHOW_TV_INFO,
			SHOW_TV_STATE,
			STOP = -1
		};

		cout << "POWER : " << POWER << endl;
		cout << "CHANNERL_UP : " << CHANNERL_UP << endl;
		cout << "CHANNERL_DOWN : " << CHANNERL_DOWN << endl;
		cout << "CHANNEL_SET : " << CHANNEL_SET << endl;
		cout << "VOLUME_UP : " << VOLUME_UP << endl;
		cout << "VOLUME_DOWN : " << VOLUME_DOWN << endl;
		cout << "SHOW_TV_INFO : " << SHOW_TV_INFO << endl;
		cout << "SHOW_TV_STATE : " << SHOW_TV_STATE << endl;
		cout << "STOP : " << STOP << endl;

		int command;
		while (true)
		{
			cin >> command;

			switch (command)
			{
			case POWER:
				_myTV.Power();
				break;
			case CHANNERL_UP:
				_myTV.ChannelUp();
				break;
			case CHANNERL_DOWN:
				_myTV.ChannelDown();
				break;
			case CHANNEL_SET:
				int channel;
				cout << "ä�� �Է� : ";
				cin >> channel;
				_myTV.SetChannel(channel);
				break;
			case VOLUME_UP:
				_myTV.VolumeUp();
				break;
			case VOLUME_DOWN:
				_myTV.VolumeDown();
				break;
			case SHOW_TV_INFO:
				_myTV.ShowInfo();
				break;
			case SHOW_TV_STATE:
				_myTV.ShowTVState();
				break;
			case STOP:
				return;
			default:
				cout << "0~5�� ����" << endl;
				break;
			}
		}
	}
	void SetMyTV(C_TV tv)
	{
		_myTV = tv;
		_isHaveTV = true;
	}
};

void TVTestMain()
{
	C_TV myTv = C_TV(0, C_TV::E_line_id::NORMAL, C_TV::E_shape::STAND);
	myTv.ShowInfo();
	myTv.ShowTVState();

	myTv.Power();
	myTv.SetChannel(3);
	myTv.ChannelUp();
	myTv.ChannelDown();

	myTv.VolumeUp();
	myTv.VolumeUp();
	myTv.VolumeUp();
	myTv.VolumeUp();
	myTv.VolumeDown();
}

void TVShopTestMain()
{
	C_Store* store = new C_Store();
	C_LivingRoom* myLivingRoom = new C_LivingRoom();
	
	int command;
	
	while (true)
	{
		cout << "1. tv ���� / 2. �� �Ž�" << endl;
		cin >> command;

		switch (command)
		{
		case 1:
			//myLivingRoom->SetMyTV(store->TakeOut(0));
			store->ShowDeskInfo();
			cout << "������ tv ����" << endl;
			int num;
			cin >> num;
			myLivingRoom->SetMyTV(store->TakeOut(num));
			cout << "���� �Ϸ�" << endl;
			break;
		case 2:
			myLivingRoom->OperateMyTV();
			break;
		default:
			break;
		}
	}
}


void main()
{
	//TVTestMain();
	TVShopTestMain();
}