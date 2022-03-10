#include <stdio.h>

struct sNode
{
	int key;
	sNode* pNext;
};

sNode* CreateNode(sNode* pEnd, int data);	//노드 생성
sNode* FindNodeData(sNode* pEnd, int data); //노드 검색
sNode* InsertNodeData(sNode* pEnd, int data, int insert);	//노드 삽입
sNode* DeleteNodeData(sNode* pEnd, int del);	//노드 삭제
void PrintLinkedList(sNode* pEnd); //리스트 출력
sNode* ReverseLinkedList(sNode* pEnd);	//리스트 뒤집기

void main()
{
	//환형 연결리스트에서는 마지막 노드의 다음이 시작이므로 마지막 노드만 저장해둔다.
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
	//새로생성한 노드를 pNode의 다음 포인터로 연결
	if (pEnd)
	{
		temp->pNext = pEnd->pNext;
		pEnd->pNext = temp;
	}
	else
		temp->pNext = temp;
	//pEnd가 NULL일 경우 연결리스트의 첫 노드가 필요하므로 노드 생성하여 다음을 자기자신으로 하여 리턴
	return temp;
}
sNode* FindNodeData(sNode* pEnd, int data)
{
	sNode* pNode = pEnd->pNext;
	//pNode의 끝까지 순회
	do
	{
		//찾는 값이 있으면 해당 노드를 바로 리턴
		if (pNode->key == data)
			return pNode;
		//찾는 값과 매치하지않을 경우 pNode를 다음 노드로 변경한다.
		pNode = pNode->pNext;
	} while (pNode != pEnd->pNext);
	return NULL;
}
sNode* InsertNodeData(sNode* pEnd, int data, int insert)
{
	sNode* pNode = pEnd->pNext;
	sNode* pInsert = NULL;

	pNode = FindNodeData(pEnd, data);
	//pNode 뒤에 insert 데이터를 가진 노드 추가
	if (pNode)
		CreateNode(pNode, insert);	//CreateNode()가 전달된 노드의 다음에 삽입되도록 구현되어있음.
	else
		printf("리스트에 다음 값이 없습니다 : %d\n", data);
	//FindNodeData() 함수에서 찾는 값이 없을 경우 NULL을 반환하도록 하였다.

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
	printf("리스트에 다음 값이 없습니다 : %d\n", del);
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