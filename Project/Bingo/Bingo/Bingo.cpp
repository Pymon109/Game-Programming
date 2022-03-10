#include <stdio.h>									
#include <cstdlib>									
#include <time.h>									
struct Index
{
	int _i;
	int _j;
};
struct NumSet
{
	bool _data;
	Index _indexP1;
	Index _indexP2;
};

void Suffle(int scale, NumSet numberSet[266], int Go[15][15], bool isP1);
void PrintGo(int scale, NumSet numberSet[226], int GO[15][15]);
void PrintGo2(int P1Go[15][15], int P2Go[15][15], NumSet numberSet[226], int scale);
int CheckBingo(int scale, NumSet numberSet[226], int GO[15][15], bool isP1);
void InserNumber(int scale, NumSet numberSet[226]);
void AIAttack(int scale, NumSet numberSet[226], int GO[15][15]);
void InitData(int scale, NumSet numberSet[226]);

void BingMainSolo()
{
	int GO[15][15] = {};
	NumSet numberSet[226] = { false };

	int scale = -1;
	srand(time(NULL));

	while (true)
	{
		printf("������ ũ�⸦ �Է��ϼ��� (5~15) : ");
		scanf_s("%d", &scale);
		if (scale >= 5 && scale <= 15)
			break;
		else
			printf("���� �ʰ�. ������ ũ�⸦ �Է��ϼ��� (5~15) : ");
	}
	Suffle(scale, numberSet, GO, true);
	InitData(scale, numberSet);
	PrintGo(scale, numberSet, GO);
	//���� ����
	while (true)
	{
		InserNumber(scale, numberSet);
		PrintGo(scale, numberSet, GO);
		//���� üũ
		int bingoCount = CheckBingo(scale, numberSet, GO,true);
		if (bingoCount >= scale)
			return;
	}
}
void BingoMainAI()
{
	int P1Go[15][15] = {};
	int P2Go[15][15] = {};
	NumSet numberSet[226] = {};

	int scale = -1;
	srand(time(NULL));

	while (true)
	{
		printf("������ ũ�⸦ �Է��ϼ��� (5~15) : ");
		scanf_s("%d", &scale);
		if (scale >= 5 && scale <= 15)
			break;
		else
			printf("���� �ʰ�. ������ ũ�⸦ �Է��ϼ��� (5~15) : ");
	}
	/*
	printf("Player 1�� �������� �Է��ϼ���. \n");
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			int input;
			scanf_s("%d", &input);

			P1Go[i][j] = input;
			numberSet[input]._data = true;
			numberSet[input]._indexP1._i = i;
			numberSet[input]._indexP1._j = j;
		}
	}
	//������ ���� ����							
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			int temp = (rand() % (scale * scale)) + 1;
			if (!numberSet[temp]._data)
			{
				int n = temp;
				for (int k = 0; k < scale * scale; k++)
				{
					if (!numberSet[n % (scale * scale) + 1]._data)
					{
						n++;
						continue;
					}
					else
					{
						temp = (n % (scale * scale)) + 1;
						break;
					}
				}
			}
			P2Go[i][j] = temp;
			numberSet[temp]._data = false;
			numberSet[temp]._indexP2._i = i;
			numberSet[temp]._indexP2._j = j;
		}
	}
	*/
	Suffle(scale, numberSet, P1Go, true);
	Suffle(scale, numberSet, P2Go, false);
	InitData(scale, numberSet);
	PrintGo2(P1Go, P2Go, numberSet, scale);

	//���� ����								
	while (true)
	{
		InserNumber(scale, numberSet);
		AIAttack(scale, numberSet, P2Go);
		int bingoCountP1 = CheckBingo(scale, numberSet, P1Go, true);
		int bingoCountP2 = CheckBingo(scale, numberSet, P2Go, false);
		if (bingoCountP1 >= scale)
		{
			printf("�÷��̾� �¸�!");
			return;
		}
		else if (bingoCountP2 >= scale)
		{
			printf("��ǻ�� �¸�!");
			return;
		}
		PrintGo2(P1Go, P2Go, numberSet, scale);

	}
}

int main()
{
	int command = -1;
	printf("�÷��� ��带 �Է��ϼ���(1. ȥ�� ���, 2. ��ǻ�Ͷ� �ϱ�) : ");
	while (true)
	{
		scanf_s("%d", &command);
		switch (command)
		{
		case 1:
			BingMainSolo();
			return 0;
		case 2:
			BingoMainAI();
			return 0;
		default:
			printf("�Է°� ����. 1,2�� �������ּ��� : ");
			break;
		}
	}
}

void Suffle(int scale, NumSet numberSet[266], int Go[15][15], bool isP1)
{
	for (int i = 0; i < scale * scale; i++)
		numberSet[i]._data = false;
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			int temp = (rand() % (scale * scale)) + 1;
			if (numberSet[temp]._data)
			{
				int n = temp;
				for (int k = 0; k < scale * scale; k++)
				{
					if (numberSet[n % (scale * scale) + 1]._data)
					{
						n++;
						continue;
					}
					else
					{
						temp = (n % (scale * scale)) + 1;
						break;
					}
				}
			}
			Go[i][j] = temp;
			numberSet[temp]._data = true;
			if (isP1)
			{
				numberSet[temp]._indexP1._i = i;
				numberSet[temp]._indexP1._j = j;
			}
			else
			{
				numberSet[temp]._indexP2._i = i;
				numberSet[temp]._indexP2._j = j;
			}

		}
	}
}
void PrintGo(int scale, NumSet numberSet[226], int GO[15][15])
{
	printf("�� ����\n");
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			//p1 ���						
			if (!numberSet[GO[i][j]]._data)
				printf("%2d ", GO[i][j]);
			else
				printf("XX ");
		}
		printf("\n");
	}
}
void PrintGo2(int P1Go[15][15], int P2Go[15][15], NumSet numberSet[226], int scale)
{
	printf("�� ����	\t\t\t\t\t\t\t ��ǻ�� ����\n");
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			//p1 ���						
			if (!numberSet[P1Go[i][j]]._data)
				printf("%2d ", P1Go[i][j]);
			else
				printf("XX ");
		}
		printf("\t\t\t\t\t\t\t");
		for (int j = 0; j < scale; j++)
		{
			//p2 ���						
			if (!numberSet[P2Go[i][j]]._data)
				printf("XX ");
			else
				printf("%2d ", P2Go[i][j]);
		}
		printf("\n");
	}
}
int CheckBingo(int scale, NumSet numberSet[226], int GO[15][15], bool isP1)
{
	bool bingo[32] = { false };
	for (int n = 0; n < (scale * 2) + 2; n++)
		bingo[n] = true;
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			bingo[i * 2] &= numberSet[GO[i][j]]._data;
			bingo[(j * 2) + 1] &= numberSet[GO[i][j]]._data;
			if (i == j)
				bingo[scale * 2] &= numberSet[GO[i][j]]._data;
			if ((i + j) == (scale - 1))
				bingo[(scale * 2) + 1] &= numberSet[GO[i][j]]._data;
		}
	}
	//������ ���							
	int bingoCount = 0;
	for (int n = 0; n < 32; n++)
		if (bingo[n])
			bingoCount++;
	if(isP1)
		printf("�÷��̾� %d����!\n", bingoCount);
	else
		printf("��ǻ�� %d����!\n", bingoCount);
	return bingoCount;
}
void InserNumber(int scale, NumSet numberSet[226])
{
	int input = -1;
	printf("���ڸ� �����ϼ��� : ");
	while (true)
	{
		scanf_s("%d", &input);
		if (input > scale * scale || input < 1)
		{
			//���� �ʰ� ����ó��						
			printf("���� �ʰ�. 1~%d ������ ���ڸ� �Է��ϼ��� : ", scale * scale);
			continue;
		}
		if (numberSet[input]._data)
		{
			//�̹� ���õ� ���� ����ó��						
			printf("�������� ���� ���ڸ� �Է��ϼ��� : ");
			continue;
		}
		break;
	}
	numberSet[input]._data = true;
}
void AIAttack(int scale, NumSet numberSet[226], int GO[15][15])
{
	int checkCount[32] = { 0, };
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			if (numberSet[GO[i][j]]._data)
			{
				checkCount[i * 2]++;
				checkCount[(j * 2) + 1]++;
				if (i == j)
					checkCount[scale * 2]++;
				if ((i + j) == (scale - 1))
					checkCount[(scale * 2) + 1]++;
			}
		}
	}
	int maxCount = 0;
	int index = -1;
	for (int i = 0; i < (scale + 1) * 2; i++)
	{
		int temp = checkCount[i];
		if (temp >= maxCount && temp < 5)
		{
			maxCount = temp;
			index = i;
		}
	}
	int P2Attack = -1;
	if (index == scale * 2)
	{
		//�밢�� 1
		for (int i = 0; i < scale; i++)
		{
			if (!numberSet[GO[i][i]]._data)
			{
				P2Attack = GO[i][i];
				break;
			}
		}
	}
	else if (index == (scale * 2) + 1)
	{
		//�밢�� 2
		for (int i = 0; i < scale; i++)
		{
			int j = scale - i - 1;
			if (!numberSet[GO[i][j]]._data)
			{
				P2Attack = GO[i][j];
				break;
			}
		}
	}
	else if (index % 2 == 0)
	{
		//����
		int i = index / 2;
		for (int j = 0; j < scale; j++)
		{
			if (!numberSet[GO[i][j]]._data)
			{
				P2Attack = GO[i][j];
				break;
			}
		}
	}
	else if (index % 2 == 1)
	{
		//����
		int j = (index - 1) / 2;
		for (int i = 0; i < scale; i++)
		{
			if (!numberSet[GO[i][j]]._data)
			{
				P2Attack = GO[i][j];
				break;
			}
		}
	}
	printf("��ǻ���� ���� ���� : %d\n", P2Attack);
	numberSet[P2Attack]._data = true;
}
void InitData(int scale, NumSet numberSet[226])
{
	for (int i = 0; i <= scale * scale; i++)
		numberSet[i]._data = false;
}