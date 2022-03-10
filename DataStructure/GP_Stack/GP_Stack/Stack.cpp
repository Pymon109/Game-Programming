#include <stdio.h>
#define MAXSIZE 100

struct sNode
{
	sNode* pNext;
	int key;
};

//배열 스택을 위한 함수
void AstackPush(int stack[], int& end, int data);
void AstackPop(int& end);
void AstackPrint(int stack[], int& end);

void ArrayStackMain()
{
	//배열로 스택 구현
	int Astack[MAXSIZE] = { 0, };
	int AstackEnd = -1;

	printf("//////////////////////////////////////////////배열 스택\n");

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

//연결리스트 스택을 위한 함수
sNode* LstackPush(sNode* top, int data);
sNode* LstackPop(sNode* top);
void LstackPrint(sNode* top);

void LinkedListStatcMain()
{
	//연결리스트로 스택 구현
	sNode* top = NULL;	//맨 위(가장 끝) 노드

	printf("////////////////////////////////////////연결리스트 스택\n");

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


//배열 스택을 위한 함수
void AstackPush(int stack[], int& end, int data)
{
	if (end >= MAXSIZE-1)
	{
		printf("Astack error : 스택 크기 초과.\n");
		return;
	}
	stack[++end] = data;
}
void AstackPop(int& end)
{
	if (end < 0)
	{
		printf("error : 스택에 인자 없음.\n");
		return;
	}
	--end;
}
void AstackPrint(int stack[], int& end)
{
	if (end < 0)
	{
		printf("Astack error : 스택에 인자 없음.\n");
		return;
	}
	printf("Astack data : ");
	for (int i = end; i >= 0; i--)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

//리스트 스택을 위한 함수
sNode* LstackPush(sNode* top, int data)
{
	sNode* temp = NULL;
	temp = new sNode();
	temp->key = data;
	if (top)		//top이 null일 경우 스택은 빈 상태.
		temp->pNext = top;	//creatNode()와 다른 부분.

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
		printf("스택에 인자 없음.\n");
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