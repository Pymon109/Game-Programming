#include <stdio.h>

typedef struct tNode
{
	int key;
	tNode* left;
	tNode* right;
};
typedef struct Stack
{
	tNode* key;
	Stack* pNext;
};
Stack* StackPush(Stack* top, tNode* data);
Stack* StackPop(Stack* top);
void DeleteStatck(Stack* top);

tNode* Test_Create(tNode* pNode, int data, bool isRight);

tNode* FindEnd(tNode* pRoot);
Stack* Preorder(tNode* pNode, int& maxLv, int& curLv, Stack* top);

void main()
{
	tNode* pRoot = NULL;

	pRoot = Test_Create(pRoot, 10, true);
	Test_Create(pRoot, 20, false);
	Test_Create(pRoot, 30, true);
	Test_Create(pRoot->left, 40, false);
	Test_Create(pRoot->left, 50, true);
	Test_Create(pRoot->right, 60, false);
	Test_Create(pRoot->right, 70, true);

	FindEnd(pRoot);
}

tNode* Test_Create(tNode* pNode, int data, bool isRight)
{
	tNode* temp = new tNode();
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


Stack* StackPush(Stack* top, tNode* data)
{
	Stack* temp = NULL;
	temp = new Stack();
	temp->key = data;
	if (top)		//top�� null�� ��� ������ �� ����.
		temp->pNext = top;	//creatNode()�� �ٸ� �κ�.

	return temp;
}
Stack* StackPop(Stack* top)
{
	Stack* pReturn = NULL;
	if (top)
	{
		pReturn = top->pNext;
		delete(top);
	}
	else
		printf("���ÿ� ���� ����.\n");
	return pReturn;
}
void DeleteStatck(Stack* top)
{
	Stack* pNode = top;
	Stack* temp = NULL;
	while (pNode)
	{
		temp = pNode;
		pNode = pNode->pNext;
		delete(temp);
	}
}

tNode* FindEnd(tNode* pRoot)
{
	int maxLv = 0;
	int curLv = 0;
	
	Stack* top = NULL;

	top = Preorder(pRoot, maxLv, curLv, top);

	return pRoot;
}

Stack* Preorder(tNode* pNode, int &maxLv, int&curLv, Stack* top)
{
	curLv++;
	//���� > ������ > �θ�
	if (pNode)
	{
		if (curLv > maxLv)
		{
			maxLv = curLv;
			DeleteStatck(top);
			top = NULL;
			top = StackPush(top, pNode);
		}
		else if (curLv == maxLv)
			top = StackPush(top, pNode);
			
		//printf("%d ", pNode->key);
		top = Preorder(pNode->left, maxLv, curLv, top);
		top = Preorder(pNode->right, maxLv, curLv, top);
	}
	curLv--;
	return top;
}
