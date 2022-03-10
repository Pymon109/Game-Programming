#include <iostream>
#include <list>
#include <time.h>
#include <string>
#include <bitset>
using namespace std;

#define MAX_BUCKET_SIZE 100


void MainMyHash();
void MainMD5();


void main()
{
	MainMyHash();
	MainMD5();
}



//MainMyHash()를 위한 버킷
list<string> bucket[MAX_BUCKET_SIZE]; //충돌 예외처리로 체이닝 사용

//MainMyHash()를 위한 함수
void MyHash_AddData(const char* key);
int MyHash_Function(const char* key);
list<string>::iterator MyHash_FindData(const char* key, int& id);
void MyHash_DeleteData(const char* key);
void MyHash_PrintTable();

void MainMyHash()
{
	cout << "*************************************************** // MyHash" << endl;

	MyHash_AddData("apple");
	MyHash_AddData("boy");
	MyHash_AddData("color");
	MyHash_AddData("abs");
	MyHash_AddData("cool");
	MyHash_AddData("flower");
	MyHash_AddData("queue");
	MyHash_AddData("Hellow World! It's beautiful day!");

	MyHash_PrintTable();

	list<string>::iterator find;
	int id;
	find = MyHash_FindData("apple", id);
	find = MyHash_FindData("pizza", id);

	MyHash_DeleteData("a");
	MyHash_DeleteData("apple");

	MyHash_PrintTable();
}

int MyHash_Function(const char* key)
{
	long long int hash = 0;
	for (int i = 0; key[i] != NULL; i++)
		hash += key[i];
	return hash % MAX_BUCKET_SIZE;
}
void MyHash_AddData(const char* key)
{
	int id = MyHash_Function(key);
	bucket[id].push_back(key);
}
list<string>::iterator MyHash_FindData(const char* key, int& id)
{
	id = MyHash_Function(key);
	if (!bucket[id].empty())
	{
		string sKey = key;
		list<string>::iterator it = bucket[id].begin();
		for (list<string>::iterator it = bucket[id].begin(); it != bucket[id].end(); it++)
		{
			string sIt = *it;
			if (sKey.compare(sIt) == 0)
			{
				cout << "Find (" << key << "), id : " << id << endl;
				return it;
			}
		}
	}
	cout << "(" << key << ")is not in the table." << endl;
	return bucket[id].end();
}
void MyHash_DeleteData(const char* key)
{
	int id;
	list<string>::iterator it = MyHash_FindData(key, id);
	if (it != bucket[id].end())
	{
		bucket[id].erase(it);
		cout << "Delete (" << key << "), id : " << id << endl;
	}
}
void MyHash_PrintTable()
{
	cout << "Display Hash Table ============================" << endl;
	for (int i = 0; i < MAX_BUCKET_SIZE; i++)
	{
		if (!bucket[i].empty())
		{
			list<string>::iterator it = bucket[i].begin();
			cout << "[" << i << "] : ";
			for (list<string>::iterator it = bucket[i].begin(); it != bucket[i].end(); it++)
				cout << "(" << *it << ") ";
			cout << endl;
		}
	}
}

//MD5를 위한 정의 및 매크로
#define MD5_MSG_UNIT_BIT_SIZE 512
#define MD5_MSG_UNIT_B_SIZE 64
#define MD5_HASH_BIT_SIZE 128

#define F(x,y,z) ((x&y)|((~x)&z))
#define G(x,y,z) ((x&z)|(y&(~z)))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y^(x|(~z)))

//패딩을 위한 단위 구조체
typedef struct pad
{
	char unit[MD5_MSG_UNIT_B_SIZE];
};

//MD5를 위한 버킷


//MD5를 위한 함수
void MD5_Function(string msg);


void MainMD5()
{
	cout << "*************************************************** // MD5" << endl;
	string s = "abcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxzabcdefghijklmnopqrstuvwyxz";
	MD5_Function(s);
}

void MD5_Function(string msg)
{
	//패딩
	list<pad> p;
	int msg_length = msg.length();
	int c = 128;

	for (int i = 0; i < (msg.length() / 64) + 1; i++)
	{
		pad* temp = new pad();
		*temp->unit = { 0, };
		int unitSize = 64;
		if (i == msg.length() / 64)
			unitSize = msg.length() - (64 * i);
		for (int j = 0; j < unitSize; j++)
		{
			temp->unit[j] |= msg.c_str()[(i * 63) + j];
		}
		if (i == msg.length() / 64)
			temp->unit[unitSize] |= c;
		p.push_back(*temp);
	}

	list<pad>::iterator it = p.begin();

	cout << "list<pad>" << endl;
	for (int i = 0; it != p.end(); it++)
	{
		cout << "[" << i++ << "] : " << (*it).unit << endl;
	}
	
	//암호화 알고리즘

}