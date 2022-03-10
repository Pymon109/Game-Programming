#include <stdio.h>
#define MAXSIZE 100

struct sNode
{
	sNode* pNext;
	int key;
};

//�迭 ť�� ���� �Լ�
bool AqueueIsFull(int start, int end);
bool AqueueIsEmpty(int start, int end);
void AqueuePush(int stack[], int& start, int& end, int data);
void AqueuePop(int& start, int& end);
void AqueuePrint(int stack[], int& start, int& end);

void ArrayQueueMain()
{
	//�迭�� ť ����
	int AQueue[MAXSIZE] = { 0, };
	int AQueuFront = 0;
	int AQueueRear = 99;

	printf("//////////////////////////////////////////////�迭 ť\n");
	AqueuePop(AQueuFront, AQueueRear);
	AqueuePush(AQueue, AQueuFront, AQueueRear, 10);
	AqueuePush(AQueue, AQueuFront, AQueueRear, 20);
	AqueuePush(AQueue, AQueuFront, AQueueRear, 30);
	AqueuePush(AQueue, AQueuFront, AQueueRear, 40);
	AqueuePrint(AQueue, AQueuFront, AQueueRear);
	AqueuePop(AQueuFront, AQueueRear);
	AqueuePush(AQueue, AQueuFront, AQueueRear, 50);
	AqueuePrint(AQueue, AQueuFront, AQueueRear);
	AqueuePop(AQueuFront, AQueueRear);
	AqueuePop(AQueuFront, AQueueRear);
	AqueuePop(AQueuFront, AQueueRear);
	AqueuePrint(AQueue, AQueuFront, AQueueRear);
	AqueuePop(AQueuFront, AQueueRear);
	AqueuePop(AQueuFront, AQueueRear);
	for(int i = 0; i < MAXSIZE ; i++)
		AqueuePush(AQueue, AQueuFront, AQueueRear, i);
}

//���Ḯ��Ʈ ť�� ���� �Լ�
sNode* LqueuePush(sNode* rear, int data);
sNode* LqueuePop(sNode* front);
void LqueuePrint(sNode* front);

void LinkedListQueueMain()
{
	//���Ḯ��Ʈ�� ť ����

	printf("////////////////////////////////////////���Ḯ��Ʈ ����\n");
	sNode* pFront = NULL;
	sNode* pRear = NULL;

	pFront = LqueuePop(pFront);
	pRear = LqueuePush(pRear, 10);
	pFront = pRear;
	pRear = LqueuePush(pRear, 20);
	pRear = LqueuePush(pRear, 30);
	pRear = LqueuePush(pRear, 40);
	pRear = LqueuePush(pRear, 50);
	LqueuePrint(pFront);
	pFront = LqueuePop(pFront);
	pFront = LqueuePop(pFront);
	LqueuePrint(pFront);
}

void main()
{
	ArrayQueueMain();
	LinkedListQueueMain();

}


//�迭 ť�� ���� �Լ�
bool AqueueIsFull(int start, int end)
{
	return (((start + 2) - ((end +2) % MAXSIZE)) == 2);
}
bool AqueueIsEmpty(int start, int end)
{
	return (((start + 1) - ((end +1) % MAXSIZE)) == 1);
}
void AqueuePush(int stack[], int& start, int& end, int data)
{
	if (AqueueIsFull(start, end))
	{
		printf("Aqueue error : ť ũ�� �ʰ�.\n");
		return;
	}
	end = (end + 1) % MAXSIZE;
	stack[end] = data;
}
void AqueuePop(int& start, int& end)
{
	if (AqueueIsEmpty(start, end))
	{
		printf("Aqueue error : ���� ����.\n");
		return;
	}
	++start;
}
void AqueuePrint(int stack[], int& start, int& end)
{
	if (AqueueIsEmpty(start, end))
	{
		printf("Aqueue error : ���� ����.\n");
		return;
	}
	printf("Aqueue data : ");
	for (int i = start; i < (end+1)%MAXSIZE; (i++)%MAXSIZE)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

//����Ʈ ������ ���� �Լ�
sNode* LqueuePush(sNode* rear, int data)
{
	sNode* temp = NULL;
	temp = new sNode();
	temp->key = data;
	if (rear)		//rear�� null�� ��� ť�� �� ����.
		rear->pNext = temp;

	return temp;
}
sNode* LqueuePop(sNode* front)
{
	sNode* pReturn = NULL;
	if (front)
	{
		pReturn = front->pNext;
		delete(front);
	}
	else
		printf("Lqueue error : ���� ����.\n");
	return pReturn;
}
void LqueuePrint(sNode* front)
{
	sNode* pNode = front;
	printf("Lqueue data : ");
	while (pNode)
	{
		printf("%d ", pNode->key);
		pNode = pNode->pNext;

	}
	printf("\n");
}