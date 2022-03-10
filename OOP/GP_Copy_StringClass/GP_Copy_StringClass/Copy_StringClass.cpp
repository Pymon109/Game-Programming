#include <iostream>						
#include <stdlib.h> //�޸� �����Ҵ� ���						
#include <crtdbg.h> //�޸� ���� Ž�� ���						
using namespace std;
//���ڿ� Ŭ������ Ȱ���غ���, �ش� �Լ��� ������ ������ �����ϰ� �׽�Ʈ�� �Ͽ�						
//���������� �۵��ϴ���, Ȯ���غ���.						
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������					
	string strMsg2("DataTest"); //������					
	string srtCopyMsg = strMsg; //���������					

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test					
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01: Test					
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01:Test					
	cout << strMsg2.c_str() << endl; //DataTest					
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02: DataTest					
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x03: DataTest					
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest					
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x03:Test					
	cout << "##### STDStringMain End######" << endl;
}

namespace Mockup
{
	class string
	{
		char* pStr; //�����Ҵ�� ���ڿ��� �ּҸ� ������ ������
		int length = 0;
	public:
		string()
		{
			pStr = NULL;
		}
		//�����ڿ��� �����Ҵ�� �޸𸮴� ��ü�� �Ҹ�ɶ� ȣ��Ǿ���Ѵ�.				
		string(const char* str)
		{
			length = strlen(str) + 1;
			//�Ű������� ���� ���ڿ��� �����Ҵ�(���ڿ��� ���� +1 ��ŭ)�� ���ڿ��� �����Ϳ� �����ϰ�,			
			pStr = new char[length];
			//�����Ҵ�ȸ޸𸮿� �Ű������� ���ڿ��� �����Ѵ�.			
			strcpy_s(pStr, length, str);
			cout << "FakeString[" << this << "]:" << (int)pStr << endl;
		}
		string(const string& str)
		{
			pStr = str.pStr;
			length = strlen(str.pStr) + 1;
			pStr = new char[length];
			strcpy_s(pStr, length, str.pStr);
			//pStr = str.pStr;			

			cout << "FakeString Copy[" << this << "]:" << (int)pStr << endl;
		}
		//�����ڿ��� �����Ҵ��Ͽ����Ƿ� �ݵ�� �Ҹ��ڿ��� �����Ҵ�� ��ü�� �����Ѵ�.				
		~string()
		{
			cout << "~FakeString[" << this << "]:" << (int)pStr << endl;
			delete[] pStr;
		}
		const char* c_str()
		{
			return pStr;
		}

		int find(char input)
		{
			int i = 0;
			for (; pStr[i]; i++)
				if (pStr[i] == input)
					return i;
			return -1;
		}

		string& replace(int offset, int number, int count, const char replace)
		{
			int size = length - number + count;
			int distance = count - number;

			for (int i = length; i >= offset + number; i--)
				pStr[i + distance] = pStr[i];

			for (int i = 0; i < count; i++)
				pStr[offset + i] = replace;

			if (distance < 0)
			{
				for (int i = length; i > size; i--)
					delete (pStr + i);
			}
			length = size;
			return *this;
		}

		bool operator==(const string& str)
		{
			bool temp = true;
			return temp;
		}

		string operator+(const string& str)
		{
			string temp = str;
			return temp;
		}
		int size()
		{
			return length - 1;
		}
		char operator[](int index)
		{
			char temp = 'a';
			return temp;
		}
	};
}
void MockupStringMain()
{
	cout << "##### FakeStringMain Start ######" << endl;
	Mockup::string strMsg("Test"); //������					
	Mockup::string strMsg2("DataTest"); //������					
	Mockup::string srtCopyMsg = strMsg; //���������					
	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test					
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01: Test					
	cout << strMsg2.c_str() << endl; //DataTest					
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02: DataTest					
	cout << srtCopyMsg.c_str() << endl; //0x01: Test					
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x02: DataTest					
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x01:Test -> 0x03:Test					
	cout << "##### FakeStringMain End######" << endl;
}

void MockUpHangManGameMain()
{

	Mockup::string strAnswer = "GAME";
	Mockup::string strEmpty = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		cin >> cInput;
		//scanf("%c", &cInput);				

		int nResultIdx = strAnswer.find(cInput);//ã�� ���ڿ��� �ּҰ��� ��ȯ�Ѵ�.				
		if (nResultIdx != -1)
		{
			//ã�� ���ڿ����ּҿ��� ���ڿ������ּҸ� ���� ���� �ε������� ����Ѵ�.			
			strEmpty.replace(nResultIdx, 1, 1, cInput);
		}
		else
			printf("not found!\n");

		if (strAnswer == strEmpty)
		{
			printf("Q:%s\n", strEmpty.c_str());
			break;
		}
		else
			printf("strcmp:%d\n", nResultIdx);
	}
	//for (int i = 0; i < strAnswer.size(); i++)					
	//	cout << i << ":" << strAnswer[i];				
	//Mockup::string strTemp = strAnswer + strEmpty;					
}

void HangManGameMain()
{

	string strAnswer = "GAME";
	::string strEmpty = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		cin >> cInput;
		//scanf("%c", &cInput);				

		int nResultIdx = strAnswer.find(cInput);//ã�� ���ڿ��� �ּҰ��� ��ȯ�Ѵ�.				
		if (nResultIdx != -1)
		{
			//ã�� ���ڿ����ּҿ��� ���ڿ������ּҸ� ���� ���� �ε������� ����Ѵ�.			
			strEmpty.replace(nResultIdx, 1, 1, cInput);
		}
		else
			printf("not found!\n");

		if (strAnswer == strEmpty)
		{
			printf("Q:%s\n", strEmpty.c_str());
			break;
		}
		else
			printf("strcmp:%d\n", nResultIdx);
	}
	//for (int i = 0; i < strAnswer.size(); i++)					
	//	cout << i << ":" << strAnswer[i];				
	//Mockup::string strTemp = strAnswer + strEmpty;					
}


void main()
{
	//_CrtSetBreakAlloc(150); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.					
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻�					
	//STDStringMain();					
	//MockupStringMain();					
	MockUpHangManGameMain();
}