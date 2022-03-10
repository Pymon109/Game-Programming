#include <stdio.h>

typedef struct sNode
{
	int key;
	sNode* left;
	sNode* right;
};


void Preorder(sNode* pNode); //���� ��ȸ : �θ� > ���� > ������ (�θ� ����)
void Inorder(sNode* pNode); //���� ��ȸ : ���� > �θ� > ������
void Postorder(sNode* pNode); //���� ��ȸ : ���� > ������ > �θ� (���� ��� ����)
sNode* CreateNode(sNode* pNode, int data, bool isRight);	//��� ����
//��� �˻�
//��� ���� (��� �˻� �� ����)
//��� ���� (��� �˻� �� ����)


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
				printf("error : �ش� ����� �����ʿ� �����Ͱ� �ֽ��ϴ�.");
			else
				pNode->right = temp;
			break;
		case false:
			if (pNode->left)
				printf("error : �ش� ����� ���ʿ� �����Ͱ� �ֽ��ϴ�.");
			else
				pNode->left = temp;
			break;
		}
	}
	return temp;
}

void Preorder(sNode* pNode)
{
	//�θ� > ���� > ������ (�θ� ����)
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
	//���� > �θ� > ������
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
	//���� > ������ > �θ�
	if (pNode)
	{
		Postorder(pNode->left);
		Postorder(pNode->right);
		printf("%d ", pNode->key);
	}
	return;
}