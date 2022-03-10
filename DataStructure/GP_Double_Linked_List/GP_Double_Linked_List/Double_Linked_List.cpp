#include <stdio.h>

struct sNode
{
	int key;
	sNode* pPre;
	sNode* pNext;
};

sNode* CreateNode(sNode* pNode, int data);	//��� ����
sNode* FindNodeData(sNode* pStart, int data);	//��� �˻�
sNode* InsertNodeData(sNode* pStart, int data, int insert);	//��� ����
sNode* DeleteNodeData(sNode* pStart, int del);	//��� ����
void PrintLinkedList(sNode* pStart);	//��� ���
sNode* ReverseLinkedList(sNode* pStart); //����Ʈ ������
sNode* FindEndNode(sNode* pStart);

void main()
{
	sNode* pBegin = NULL;	//top ����� Ư¡ : pre �����Ͱ� �׻� null
	sNode* pEnd = NULL;		//end ����� Ư¡ : next �����Ͱ� �׻� null

	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd;
	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);
	PrintLinkedList(pBegin);

	sNode* pFind = FindNodeData(pBegin, 40);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->key);
	else
		printf("Not Found.\n");

	InsertNodeData(pBegin, 20, 70);
	PrintLinkedList(pBegin);

	sNode* pDel = DeleteNodeData(pBegin, 50);
	if (pDel != NULL)
		pBegin = pDel;
	pEnd = FindEndNode(pBegin);
	PrintLinkedList(pBegin);

	sNode* temp = pEnd;
	pEnd = ReverseLinkedList(pBegin);
	pBegin = temp;
	PrintLinkedList(pBegin);

}

sNode* CreateNode(sNode* pNode, int data)
{
	sNode* temp = NULL;

	temp = new sNode();
	temp->key = data;
	if (pNode)
	{
		pNode->pNext = temp;
		temp->pPre = pNode;
	}
	return temp;
}
sNode* FindNodeData(sNode* pStart, int data)
{
	sNode* pNode = pStart;
	while (pNode)
	{
		if (pNode->key == data)
			return pNode;
		pNode = pNode->pNext;
	}
	return NULL;
}

sNode* InsertNodeData(sNode* pStart, int data, int insert)
{
	sNode* pNode = pStart;
	sNode* pInsert = NULL;

	pNode = FindNodeData(pStart, data);
	if (pNode)
	{
		pInsert = new sNode();
		pInsert->key = insert;

		pInsert->pNext = pNode->pNext;	//���� ��� -> ã�� ����� ���� ��� ����
		pInsert->pPre = pNode;	//���� ����� ���� ��� -> ã�� ���� ����
		pNode->pNext->pPre = pInsert;	//���Գ���� ������� -> ���Գ�� ����
		pNode->pNext = pInsert;	//ã�� ��� -> ���� ��� ����
	}
	else
		printf("����Ʈ�� ���� ���� �����ϴ� : %d\n", data);

	return pNode;
}

sNode* DeleteNodeData(sNode* pStart, int del)
{
	sNode* pReturn = NULL;
	sNode* pNode = FindNodeData(pStart, del);

	if (pNode)
	{
		if (pNode == pStart)	//���� ��尡 ù����� ���
		{
			pReturn = pStart->pNext;
			pReturn->pPre = NULL;
		}
		else if (pNode->pNext == NULL)	//���� ��尡 ������ ����� ���
			pNode->pPre->pNext = NULL;
		else
		{
			if (pNode->pPre)
			{
				sNode* pPre = pNode->pPre;
				pPre->pNext = pNode->pNext;
				pNode->pPre = pPre;
			}
		}
		delete(pNode);
	}
	else
		printf("����Ʈ�� ���� ���� �����ϴ� : %d\n", del);

	return pReturn;

}

sNode* FindEndNode(sNode* pStart)
{
	sNode* pNode = pStart;
	while (pNode)
	{
		if (pNode->pNext == NULL)
			return pNode;
		pNode = pNode->pNext;
	}
	return NULL;
}

sNode* ReverseLinkedList(sNode* pStart)
{
	sNode* pNode = pStart;
	while (pNode)
	{
		sNode* temp = pNode->pPre;
		pNode->pPre = pNode->pNext;
		pNode->pNext = temp;

		pNode = pNode->pPre;
	}

	return pStart;
}

void PrintLinkedList(sNode* pStart)
{
	sNode* pNode = pStart;
	printf("data : ");
	while (pNode)
	{
		printf("%d", pNode->key);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(" , ");
	}
	printf("\n");
}