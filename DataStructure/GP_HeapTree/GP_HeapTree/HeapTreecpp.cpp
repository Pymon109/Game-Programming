#include <stdio.h>

#define STACKSIZE 100

//�����ʹ� ���� ������ �߰��ȴ�.
//�θ�� �ڽĺ��� �۴�.
//�ڽĳ�尡 ����ִٸ�, ���ʺ��� ä���.
//�ڽĳ�� �� �ڽ��� ����� ������ ä���.
//�ڽ��� ��� �� �ִٸ�, ���� ������ ������ ä���.

//ä��� �켱 ����
// 1. ���� �ڽ�
// 2. ������ �ڽ�
// 3. ���� ���
// 4. ������ �ƴ� ���� ���� ���
// 5. �ڽ��� (1~4) ���� 

#define HEAP_MAX_SIZE 100
#define HEAP_FULL(n) (n == HEAP_MAX_SIZE -1)
#define HEAP_EMPTY(n) (n<0)
#define HEAP_LEFT_CHILD(n) ((n*2)+1)
#define HEAP_RIGHT_CHILD(n) ((n*2)+2)
#define HEAP_PARENT(n) (n%2==0 ? (n-2)/2 : (n-1)/2 )

#define SWAP(a, b, type)  {type temp; temp = a; a = b; b = temp;}

void SequentialPushHeap(int heaps[], int& end, int data); //��� �߰� (����)
void PushHeap(int heaps[], int& end, int data); //��� �߰� (����x)
void PrintHeap(int heaps[], int& end); //���� ���
void DeleteNode(int heaps[], int& end);

void main()
{
	int heaps[HEAP_MAX_SIZE] = { 0, };
	int end = -1;

	DeleteNode(heaps, end);
	
		for (int i = 1; i < 10; i++)
		SequentialPushHeap(heaps, end, i);
	PrintHeap(heaps, end);

	DeleteNode(heaps, end);
	PrintHeap(heaps, end);


	while (true)
	{
		int data = 0;
		printf("Push data : ");
		scanf_s("%d", &data);
		PushHeap(heaps, end, data);
		PrintHeap(heaps, end);
	}

}

void SequentialPushHeap(int heaps[], int& end, int data)
{
	if (!HEAP_FULL(end))
	{
		heaps[++end] = data;
	}
	else
		printf("heap_error : Heap full.\n");
}
void PushHeap(int heaps[], int& end, int data)
{
	if (!HEAP_FULL(end))
	{
		heaps[++end] = data;
		int current = end;
		while (current > -1)
		{
			if (heaps[HEAP_PARENT(current)] > heaps[current])
			{
				SWAP(heaps[HEAP_PARENT(current)], heaps[current], int);
				current = HEAP_PARENT(current);
			}
			else
				break;
		}
	}
	else
		printf("heap_error : Heap full.\n");
}
void PrintHeap(int heaps[], int& end)
{
	printf("data : ");
	for (int i = 0; i <= end; i++)
		printf("%d ", heaps[i]);
	printf("\n");
}
void DeleteNode(int heaps[], int &end)
{
	if (!HEAP_EMPTY(end))
	{
		heaps[0] = heaps[end--];
		int current = 0;
		while (true)
		{
			int target = current;
			if (heaps[HEAP_LEFT_CHILD(current)] <= heaps[HEAP_RIGHT_CHILD(current)])
				target = HEAP_LEFT_CHILD(current);
			else
				target = HEAP_RIGHT_CHILD(current);
			if (target <= end)
			{
				if (heaps[target] < heaps[current])
				{
					SWAP(heaps[target], heaps[current], int);
					current = target;
				}
				else
					break;
			}
			else break;
		}
	}
	else
		printf("heap_error : Heap empty.\n");
}