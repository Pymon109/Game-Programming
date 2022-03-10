#include <stdio.h>
#define MAXSIZE 100

struct sNode
{
	sNode* pNext;
	int key;
};

//�迭 ������ ���� �Լ�
void AstackPush(int stack[], int& end, int data);
void AstackPop(int& end);
void AstackPrint(int stack[], int& end);

void ArrayStackMain()
{
	//�迭�� ���� ����
	int Astack[MAXSIZE] = { 0, };
	int AstackEnd = -1;

	printf("//////////////////////////////////////////////�迭 ����\n");

	AstackPush(Astack, AstackEnd, 10);
	AstackPrint(Astack, AstackEnd);
	AstackPush(Astack, AstackEnd, 20);
	AstackPrint(Astack, AstackEnd);
	AstackPush(Astack, AstackEnd, 30);
	AstackPrint(Astack, AstackEnd);
	AstackPush(Astack, AstackEnd, 40);
	AstackPrint(Astack, AstackEnd);
	AstackPop(AstackEnd);
	AstackPrint(Astack, AstackEnd);
	AstackPush(Astack, AstackEnd, 50);
	AstackPrint(Astack, AstackEnd);
	AstackPop(AstackEnd);
	AstackPrint(Astack, AstackEnd);
	AstackPop(AstackEnd);
	AstackPrint(Astack, AstackEnd);
	AstackPop(AstackEnd);
	AstackPrint(Astack, AstackEnd);
	AstackPop(AstackEnd);
	AstackPrint(Astack, AstackEnd);

	for (int i = 0; i <= MAXSIZE; i++)
	{
		AstackPush(Astack, AstackEnd, i);
	}
}

//���Ḯ��Ʈ ������ ���� �Լ�
sNode* LstackPush(sNode* top, int data);
sNode* LstackPop(sNode* top);
void LstackPrint(sNode* top);

void LinkedListStatcMain()
{
	//���Ḯ��Ʈ�� ���� ����
	sNode* top = NULL;	//�� ��(���� ��) ���

	printf("////////////////////////////////////////���Ḯ��Ʈ ����\n");

	top = LstackPush(top, 10);
	top = LstackPush(top, 20);
	top = LstackPush(top, 30);
	top = LstackPush(top, 40);
	top = LstackPush(top, 50);
	LstackPrint(top);
	top = LstackPop(top);
	top = LstackPop(top);
	LstackPrint(top);
}

void main()
{
	ArrayStackMain();
	LinkedListStatcMain();
}


//�迭 ������ ���� �Լ�
void AstackPush(int stack[], int& end, int data)
{
	if (end >= MAXSIZE-1)
	{
		printf("Astack error : ���� ũ�� �ʰ�.\n");
		return;
	}
	stack[++end] = data;
}
void AstackPop(int& end)
{
	if (end < 0)
	{
		printf("error : ���ÿ� ���� ����.\n");
		return;
	}
	--end;
}
void AstackPrint(int stack[], int& end)
{
	if (end < 0)
	{
		printf("Astack error : ���ÿ� ���� ����.\n");
		return;
	}
	printf("Astack data : ");
	for (int i = end; i >= 0; i--)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

//����Ʈ ������ ���� �Լ�
sNode* LstackPush(sNode* top, int data)
{
	sNode* temp = NULL;
	temp = new sNode();
	temp->key = data;
	if (top)		//top�� null�� ��� ������ �� ����.
		temp->pNext = top;	//creatNode()�� �ٸ� �κ�.

	return temp;
}
sNode* LstackPop(sNode* top)
{
	sNode* pReturn = NULL;
	if (top)
	{
		pReturn = top->pNext;
		delete(top);
	}
	else
		printf("���ÿ� ���� ����.\n");
	return pReturn;
}
void LstackPrint(sNode* top)
{
	sNode* pNode = top;
	printf("Lstack data : ");
	while (pNode)
	{
		printf("%d ", pNode->key);
		pNode = pNode->pNext;

	}
	printf("\n");
}