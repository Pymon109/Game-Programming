#include <stdio.h>

struct sNode
{
	int key;
	sNode* pNext;
};

sNode* CreateNode(sNode* pEnd, int data);	//��� ����
sNode* FindNodeData(sNode* pEnd, int data); //��� �˻�
sNode* InsertNodeData(sNode* pEnd, int data, int insert);	//��� ����
sNode* DeleteNodeData(sNode* pEnd, int del);	//��� ����
void PrintLinkedList(sNode* pEnd); //����Ʈ ���
sNode* ReverseLinkedList(sNode* pEnd);	//����Ʈ ������

void main()
{
	//ȯ�� ���Ḯ��Ʈ������ ������ ����� ������ �����̹Ƿ� ������ ��常 �����صд�.
	sNode* pEnd = NULL;

	pEnd = CreateNode(pEnd, 10);
	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	PrintLinkedList(pEnd);

	sNode* pFind = FindNodeData(pEnd, 0);
	if (pFind)
		printf("Find :%d\n", pFind->key);
	else
		printf("Not Found.\n");

	sNode* pInsertNode = InsertNodeData(pEnd, 30, 70);
	PrintLinkedList(pEnd);

	sNode* pDelete = DeleteNodeData(pEnd, 10);
	if (pDelete != NULL)
		pEnd = pDelete;
	PrintLinkedList(pEnd);

	pEnd = CreateNode(pEnd, 80);
	PrintLinkedList(pEnd);

	pEnd = ReverseLinkedList(pEnd);
	PrintLinkedList(pEnd);

}

sNode* CreateNode(sNode* pEnd, int data)
{
	sNode* temp = NULL;

	temp = new sNode();
	temp->key = data;
	//���λ����� ��带 pNode�� ���� �����ͷ� ����
	if (pEnd)
	{
		temp->pNext = pEnd->pNext;
		pEnd->pNext = temp;
	}
	else
		temp->pNext = temp;
	//pEnd�� NULL�� ��� ���Ḯ��Ʈ�� ù ��尡 �ʿ��ϹǷ� ��� �����Ͽ� ������ �ڱ��ڽ����� �Ͽ� ����
	return temp;
}
sNode* FindNodeData(sNode* pEnd, int data)
{
	sNode* pNode = pEnd->pNext;
	//pNode�� ������ ��ȸ
	do
	{
		//ã�� ���� ������ �ش� ��带 �ٷ� ����
		if (pNode->key == data)
			return pNode;
		//ã�� ���� ��ġ�������� ��� pNode�� ���� ���� �����Ѵ�.
		pNode = pNode->pNext;
	} while (pNode != pEnd->pNext);
	return NULL;
}
sNode* InsertNodeData(sNode* pEnd, int data, int insert)
{
	sNode* pNode = pEnd->pNext;
	sNode* pInsert = NULL;

	pNode = FindNodeData(pEnd, data);
	//pNode �ڿ� insert �����͸� ���� ��� �߰�
	if (pNode)
		CreateNode(pNode, insert);	//CreateNode()�� ���޵� ����� ������ ���Եǵ��� �����Ǿ�����.
	else
		printf("����Ʈ�� ���� ���� �����ϴ� : %d\n", data);
	//FindNodeData() �Լ����� ã�� ���� ���� ��� NULL�� ��ȯ�ϵ��� �Ͽ���.

	return pNode;
}
sNode* DeleteNodeData(sNode* pEnd, int del)
{
	sNode* pPre = pEnd;
	sNode* pNode = pEnd->pNext;
	sNode* pReturn = NULL;
	do
	{
		if (pNode->key == del)
		{
			if (pPre)
				pPre->pNext = pNode->pNext;
			if (pNode == pEnd)
				pReturn = pPre;
			delete(pNode);
			break;
		}
		pPre = pNode;
		pNode = pNode->pNext;
	} while (pNode != pEnd->pNext);
	printf("����Ʈ�� ���� ���� �����ϴ� : %d\n", del);
	return pReturn;
}
void PrintLinkedList(sNode* pEnd)
{
	sNode* pNode = pEnd->pNext;
	printf("data : ");
	do
	{
		printf("%d", pNode->key);
		pNode = pNode->pNext;

		if (pNode != pEnd->pNext)
			printf(" , ");
	} while (pNode != pEnd->pNext);

	printf("\n");
}
sNode* ReverseLinkedList(sNode* pEnd)
{
	sNode* pre, * current, * next;
	pre = pEnd;
	current = pEnd->pNext;
	next = current->pNext;

	sNode* pStart = pEnd->pNext;

	do
	{
		current->pNext = pre;

		pre = current;
		current = next;
		next = next->pNext;
	} while (current != pStart);

	return current;
}