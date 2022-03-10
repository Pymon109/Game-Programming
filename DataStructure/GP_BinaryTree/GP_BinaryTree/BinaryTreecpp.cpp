#include <stdio.h>

typedef struct sNode
{
	int key;
	sNode* left;
	sNode* right;
};


void Preorder(sNode* pNode); //전위 순회 : 부모 > 왼쪽 > 오른쪽 (부모 먼저)
void Inorder(sNode* pNode); //중위 순회 : 왼쪽 > 부모 > 오른쪽
void Postorder(sNode* pNode); //후위 순회 : 왼쪽 > 오른쪽 > 부모 (하위 노드 먼저)
sNode* CreateNode(sNode* pNode, int data, bool isRight);	//노드 생성
//노드 검색
//노드 삽입 (노드 검색 후 삽입)
//노드 삭제 (노드 검색 후 삭제)


void main()
{
	sNode* pRoot = NULL;

	pRoot = CreateNode(pRoot, 10, true);
	CreateNode(pRoot, 20, false);
	CreateNode(pRoot, 30, true);
	CreateNode(pRoot->left, 40, true);
	CreateNode(pRoot->right, 50, true);

	printf("PreOrder : ");
	Preorder(pRoot);
	printf("\n");

	printf("InOrder : ");
	Inorder(pRoot);
	printf("\n");

	printf("PostOrder : ");
	Postorder(pRoot);
	printf("\n");
}


sNode* CreateNode(sNode* pNode, int data, bool isRight)
{
	sNode* temp = new sNode();
	temp->key = data;
	if (pNode)
	{
		switch (isRight)
		{
		case true:
			if (pNode->right)
				printf("error : 해당 노드의 오른쪽에 데이터가 있습니다.");
			else
				pNode->right = temp;
			break;
		case false:
			if (pNode->left)
				printf("error : 해당 노드의 왼쪽에 데이터가 있습니다.");
			else
				pNode->left = temp;
			break;
		}
	}
	return temp;
}

void Preorder(sNode* pNode)
{
	//부모 > 왼쪽 > 오른쪽 (부모 먼저)
	if (pNode)
	{
		printf("%d ", pNode->key);
		Preorder(pNode->left);
		Preorder(pNode->right);
	}
	return;
}
void Inorder(sNode* pNode)
{
	//왼쪽 > 부모 > 오른쪽
	if (pNode)
	{
		Inorder(pNode->left);
		printf("%d ", pNode->key);
		Inorder(pNode->right);
	}
	return;

}
void Postorder(sNode* pNode)
{
	//왼쪽 > 오른쪽 > 부모
	if (pNode)
	{
		Postorder(pNode->left);
		Postorder(pNode->right);
		printf("%d ", pNode->key);
	}
	return;
}