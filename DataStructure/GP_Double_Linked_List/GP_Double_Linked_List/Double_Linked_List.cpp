#include <stdio.h>

struct sNode
{
	int key;
	sNode* pPre;
	sNode* pNext;
};

sNode* CreateNode(sNode* pNode, int data);	//노드 생성
sNode* FindNodeData(sNode* pStart, int data);	//노드 검색
sNode* InsertNodeData(sNode* pStart, int data, int insert);	//노드 삽입
sNode* DeleteNodeData(sNode* pStart, int del);	//노드 삭제
void PrintLinkedList(sNode* pStart);	//노드 출력
sNode* ReverseLinkedList(sNode* pStart); //리스트 뒤집기
sNode* FindEndNode(sNode* pStart);

void main()
{
	sNode* pBegin = NULL;	//top 노드의 특징 : pre 포인터가 항상 null
	sNode* pEnd = NULL;		//end 노드의 특징 : next 포인터가 항상 null

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

		pInsert->pNext = pNode->pNext;	//삽입 노드 -> 찾은 노드의 다음 노드 연결
		pInsert->pPre = pNode;	//삽입 노드의 이전 노드 -> 찾은 노드로 연결
		pNode->pNext->pPre = pInsert;	//삽입노드의 다음노드 -> 삽입노드 연결
		pNode->pNext = pInsert;	//찾은 노드 -> 삽입 노드 연결
	}
	else
		printf("리스트에 다음 값이 없습니다 : %d\n", data);

	return pNode;
}

sNode* DeleteNodeData(sNode* pStart, int del)
{
	sNode* pReturn = NULL;
	sNode* pNode = FindNodeData(pStart, del);

	if (pNode)
	{
		if (pNode == pStart)	//삭제 노드가 첫노드일 경우
		{
			pReturn = pStart->pNext;
			pReturn->pPre = NULL;
		}
		else if (pNode->pNext == NULL)	//삭제 노드가 마지막 노드일 경우
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
		printf("리스트에 다음 값이 없습니다 : %d\n", del);

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