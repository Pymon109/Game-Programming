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
		cout << "제품 넘버 : " << _sid << endl;
		switch (_lid)
		{
		case C_TV::NORMAL:
			cout << "일반 라인" << endl;
			break;
		case C_TV::RARE:
			cout << "고급 라인" << endl;
			break;
		case C_TV::UNIQUE:
			cout << "최고급 라인" << endl;
			break;
		default:
			break;
		}
		switch (_shape)
		{
		case C_TV::STAND:
			cout << "스탠드형 티비" << endl;
			break;
		case C_TV::WALL:
			cout << "벽걸이형 티비" << endl;
			break;
		default:
			break;
		}
		cout << "====================================" << endl;
	}

	E_line_id GetLID() { return _lid; }

	//전원 조작						
	void Power()
	{
		_power = !_power;
	}

	//채널 조작						
	int GetChannel()
	{
		if (_power)
		{
			//cout << "[" << _sid << "] 현재 채널 : " << _channel << endl;
			return _channel;
		}
		return -1;
	}
	void ChannelUp()
	{
		if (_power)
		{
			_channel++;
			//cout << "[" << _sid << "] [ChannelUp] 현재 채널 : " << _channel << endl;
		}
	}
	void ChannelDown()
	{
		if (_power)
		{
			_channel--;
			//cout << "[" << _sid << "] [ChannelDown] 현재 채널 : " << _channel << endl;
		}
	}
	void SetChannel(int input)
	{
		if (_power)
		{
			_channel = input;
			//cout << "[" << _sid << "] [SetChannel] 현재 채널 : " << _channel << endl;
		}
	}

	//볼륨 조작						
	void VolumeUp()
	{
		if (_power)
		{
			_volume++;
			//cout << "[" << _sid << "] [VolumUp] 현재 볼륨 : " << _volume << endl;
		}
	}
	void VolumeDown()
	{
		if (_power)
		{
			_volume--;
			//cout << "[" << _sid << "] [VolumDown] 현재 볼륨 : " << _volume << endl;
		}
	}

	//티비 상태 보여주기						
	void ShowTVState()
	{
		if (_power)
		{
			cout << "[" << _sid << "] 화면 송출중..." << endl;
			cout << "[" << _sid << "] 현재 채널 : " << _channel << endl;
			cout << "[" << _sid << "] 볼륨 : " << _volume << endl;
		}
		else
			cout << "[" << _sid << "] 반응이 없음" << endl;
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

	//showDesk를 위한 함수
	void ShowDeskInfo()
	{
		cout << "=============================매대" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "[" << i << "] 번 상품" << endl;
			_showDesk[i].ShowInfo();
		}
	}
	
	//storage를 위한 함수
	void StoreTV(C_TV* tv)
	{
		C_TV::E_line_id LID = tv->GetLID();
		_storage[LID].push(*tv);
	}

	bool CheckStock(C_TV::E_line_id LID)
	{
		bool stoke = !_storage[LID].empty();
		if (!stoke)
			cout << "재고가 없습니다." << endl;
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
		cout << "=============================창고 적재량" << endl;
		cout << "일반 라인 : " << _storage[C_TV::E_line_id::NORMAL].size() << "개" << endl;
		cout << "고급 라인 : " << _storage[C_TV::E_line_id::RARE].size() << "개" << endl;
		cout << "최고급 라인 : " << _storage[C_TV::E_line_id::UNIQUE].size() << "개" << endl << endl;
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
			cout << "조작할 TV가 없습니다." << endl;
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
				cout << "채널 입력 : ";
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
				cout << "0~5를 선택" << endl;
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
		cout << "1. tv 매장 / 2. 내 거실" << endl;
		cin >> command;

		switch (command)
		{
		case 1:
			//myLivingRoom->SetMyTV(store->TakeOut(0));
			store->ShowDeskInfo();
			cout << "구매할 tv 선택" << endl;
			int num;
			cin >> num;
			myLivingRoom->SetMyTV(store->TakeOut(num));
			cout << "구매 완료" << endl;
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