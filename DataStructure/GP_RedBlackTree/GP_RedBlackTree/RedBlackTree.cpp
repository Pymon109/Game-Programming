#include <stdio.h>

typedef enum EColor { RED = 0, BLACK };
typedef struct tNode
{
	int key;
	tNode* parent;
	tNode* left;
	tNode* right;
	EColor color;
};


//color ��Ģ
//1. ��� ���� ������ �Ǵ� �������� ���� ������.
//2. ��Ʈ ���� �������̴�.
//3. �� ���� �������̴�.
//4. ���� ����� �ڽ��� ��� �������̴�, ������ ������ ����� �ڽ��� ������ �ʿ�� ����.
	//(��, ���� ���� ���޾� ��Ÿ�� �� ������, �� ��常�� ���� ����� �θ� ��尡 �� �� �ִ�)
//5. ��Ʈ ��忡�� ��� �� ��� ���̿� �����ϴ� ������ ����� ���� ��� �����ϴ�.

bool isLeaf(tNode* pNode);
bool IsRightChild(tNode* pNode);

void PrintTree(tNode* pRoot);
void Indorder(tNode* pNode);

tNode* InsertNode(tNode* pRoot, tNode* pLeaf, int data);
tNode* SolveDoubleRed(tNode* pRoot, tNode* pNode);
bool Recoloring(tNode* pRoot, tNode* pNode, tNode* uncle);
tNode* RotationLeft(tNode* pNode);
tNode* RotationRight(tNode* pNode);

tNode* FindNodeData(tNode* pRoot, int data);
void DelelteNode(tNode* pRoot, int data);
tNode* FindeMaxData(tNode* pNode);

tNode* Sibling(tNode* pNode);

void main()
{
	tNode* pRoot = NULL;
	tNode* pLeaf = new tNode();
	pLeaf->color = BLACK;
	pRoot = InsertNode(pRoot, pLeaf, 8);

	pRoot = InsertNode(pRoot, pLeaf, 18);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 5);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 15);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 16);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 25);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 40);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 80);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 30);
	PrintTree(pRoot);
	pRoot = InsertNode(pRoot, pLeaf, 31);
	PrintTree(pRoot);

	tNode* searcjNode = FindNodeData(pRoot, 25);
	if (!isLeaf(searcjNode))
		printf("find 25\n");

	DelelteNode(pRoot, 31);
	PrintTree(pRoot);
	DelelteNode(pRoot, 18);
	PrintTree(pRoot);

}

bool isLeaf(tNode* pNode)
{
	return (pNode->left == NULL) && (pNode->right == NULL);
}
bool IsRightChild(tNode* pNode)
{

	if (pNode)
	{
		tNode* pParent = pNode->parent;
		if (pParent)
		{
			return pParent->right == pNode;
		}
		else
			printf("NULL exception : IsRightChild(pNode) : pNode->parent is NULL\n");
	}
	else
		printf("NULL exception : IsRightChild(pNode) : pNode is NULL\n");
	return NULL;
}

void PrintTree(tNode* pRoot)
{
	printf("data : ");
	Indorder(pRoot);
	printf("\n");
}
void Indorder(tNode* pNode)
{
	//���� > �θ� > ������
	if (pNode)
	{
		Indorder(pNode->left);
		if (!isLeaf(pNode))
		{
			char color = pNode->color == RED ? 'r' : 'b';
			printf("%d(%c) ", pNode->key, color);
		}
		Indorder(pNode->right);
	}
	return;
}

tNode* InsertNode(tNode* pRoot, tNode* pLeaf, int data)
{
	tNode* temp = new tNode();
	tNode* pReturn = temp;
	temp->key = data;
	temp->color = RED;

	temp->left = pLeaf;
	temp->right = pLeaf;
	pLeaf->parent = temp;

	if (pRoot)
	{

		tNode* pNode = pRoot;
		while (pNode)
		{
			if (pNode->key >= data)
			{
				//���� Ž��
				if (isLeaf(pNode->left))
				{
					//�߰����� �� break;
					temp->parent = pNode;
					pNode->left = temp;
					break;
				}
				else
					pNode = pNode->left;
			}
			else
			{
				//������ Ž��
				if (isLeaf(pNode->right))
				{
					//�߰����� �� break;
					temp->parent = pNode;
					pNode->right = temp;
					break;
				}
				else
					pNode = pNode->right;
			}
		}

		pReturn = SolveDoubleRed(pRoot, temp);
		if (pReturn == NULL)
			pReturn = pRoot;
	}
	else
		temp->color = BLACK;
	return pReturn;
}
tNode* SolveDoubleRed(tNode* pRoot, tNode* pNode)
{
	tNode* pReturn = NULL;
	while (true)
	{
		if (pNode->parent->color == RED)
		{
			enum command
			{
				_Recoloring = 0,
				_SingleRotateRight,
				_SingleRotateLeft,
				_DobleRotateRight,
				_DoubleRotateLeft
			};
			command c;
			tNode* uncle = NULL;
			if (IsRightChild(pNode->parent))
			{
				uncle = pNode->parent->parent->left;
				if (IsRightChild(pNode))
					c = _DoubleRotateLeft;
				else
					c = _SingleRotateRight;
			}
			else
			{
				uncle = pNode->parent->parent->right;
				if (!IsRightChild(pNode))
					c = _DobleRotateRight;
				else
					c = _SingleRotateLeft;
			}
			if (uncle)
				if (uncle->color == RED)
					c = _Recoloring;

			switch (c)
			{
			case _Recoloring:
				if (Recoloring(pRoot, pNode, uncle))
				{
					pNode = pNode->parent->parent;
					continue;
				}
				else
					return pReturn;
				break;
			case _SingleRotateRight:
				pReturn = RotationRight(pNode);
				pNode = pNode->right;
				break;
			case _SingleRotateLeft:
				pReturn = RotationLeft(pNode);
				pNode = pNode->left;
				break;
			case _DobleRotateRight:
				pReturn = RotationRight(pNode->parent);
				pNode->parent->color = BLACK;
				pNode->parent->right->color = RED;
				//pNode->parent->parent->color = RED;
				break;
			case _DoubleRotateLeft:
				pReturn = RotationLeft(pNode->parent);
				pNode->parent->color = BLACK;
				pNode->parent->left->color = RED;
				break;
			default:
				break;
			}
		}
		else
			break;
	}
	return pReturn;
}
bool Recoloring(tNode* pRoot, tNode* pNode, tNode* uncle)
{
	pNode->parent->color = BLACK;
	uncle->color = BLACK;
	if (pNode->parent->parent != pRoot)
	{
		pNode->parent->parent->color = RED;
		//���÷��� �� ���� ���尡 �߻����� �ʴ��� �˻�

		return true;
	}
	else //�θ��� �θ� ��Ʈ�� ��� ���� ����� ���̻� �߻� x ����
		return false;
}
tNode* RotationLeft(tNode* pNode)
{
	tNode* pReturn = NULL;
	tNode* parent = pNode->parent;
	tNode* grandParent = pNode->parent->parent;
	tNode* lChild = pNode->left;

	if (grandParent)
	{
		if (IsRightChild(parent))
			grandParent->right = pNode;
		else
			grandParent->left = pNode;
	}
	else
	{
		//��Ʈ�� pNode�� �ٲ��.
		pReturn = pNode;
	}
	pNode->parent = grandParent;
	pNode->left = parent;
	parent->parent = pNode;

	parent->right = lChild;
	if (!isLeaf(lChild))
		lChild->parent = parent;
	return pReturn;
}
tNode* RotationRight(tNode* pNode)
{
	tNode* pReturn = NULL;
	tNode* parent = pNode->parent;
	tNode* grandParent = pNode->parent->parent;
	tNode* rChild = pNode->right;

	if (grandParent)
	{
		if (IsRightChild(parent))
			grandParent->right = pNode;
		else
			grandParent->left = pNode;
	}
	else
	{
		//��Ʈ�� pNode�� �ٲ��.
		return pReturn;
	}
	pNode->parent = grandParent;
	pNode->right = parent;
	parent->parent = pNode;

	parent->left = rChild;
	if (!isLeaf(rChild))
		rChild->parent = parent;
	return pReturn;
}

tNode* FindNodeData(tNode* pRoot, int data)
{
	tNode* pNode = pRoot;
	while (!isLeaf(pNode))
	{
		if (pNode->key == data)
			return pNode;
		else
		{
			if (pNode->key > data)
				pNode = pNode->left;
			else
				pNode = pNode->right;
		}
	}
	return pNode;
}
void DelelteNode(tNode* pRoot, int data)
{
	tNode* pTarget = FindNodeData(pRoot, data);

	tNode* pReplace = NULL;
	EColor originColor;

	bool coloringBlack = false;

	if (pTarget->color == BLACK)
		coloringBlack = true;

	//�ܼ� ����
	if (isLeaf(pTarget->left))
	{
		pReplace = pTarget->right;
		originColor = pReplace->color;

		//������ ��尡 �ڽ��� ���ų� �����ʸ� ���� ���
		if (IsRightChild(pTarget))
			pTarget->parent->right = pTarget->right;
		else
			pTarget->parent->left = pTarget->right;
		pTarget->right->parent = pTarget->parent;
		delete(pTarget);
	}
	else
	{
		//������ ��尡 ���� �ڽ��� ���� ��� (������ �ڽ��� �ְ� ���� �������)
		tNode* maxNodeLChild = FindeMaxData(pTarget->left);

		pReplace = maxNodeLChild;
		originColor = pReplace->color;

		pTarget->key = maxNodeLChild->key;

		if (IsRightChild(maxNodeLChild))
			maxNodeLChild->parent->right = maxNodeLChild->left;
		else
			maxNodeLChild->parent->left = maxNodeLChild->left;
		maxNodeLChild->left->parent = maxNodeLChild->parent;

		delete(maxNodeLChild);
	}

	if (coloringBlack)
	{
		pReplace->color = BLACK;

		if (originColor == BLACK) //���� �� �߻�. ó��
		{
			tNode* pDB = pReplace;
			while (true)
			{
				tNode* sibling = Sibling(pDB);

				if (sibling)
				{
					//CASE1. sibling�� RED
					if (sibling->color == RED)
					{
						//������ red�� ���
						if (IsRightChild(sibling))
							RotationLeft(sibling);
						else
							RotationRight(sibling);
						sibling->color = BLACK;
						pDB->parent->color = RED;
					}
					else
					{
						if (sibling->right->color == BLACK)
						{
							if (sibling->left->color == BLACK)
							{
								//CASE2_1. sibling�� BLACK�̸鼭, sibling�� child�� ��� BLACK
								//double black ����� sibling�� red�� �ٲٰ� parent�� black���� �ٲ۴�.
								pDB->parent->color = BLACK;
								sibling->color = RED;
								return;
							}
							else
							{
								//CASE2_2. sibling�� BLACK�̸鼭, sibling�� left child�� RED�̸鼭 right child�� BLACK
								sibling->color = RED;
								sibling->left->color = BLACK;
								RotationRight(sibling->left);
							}
						}
						else
						{
							//CASE2_3. sibling�� BLACK�̸鼭, sibling�� right child�� RED
							sibling->color = pDB->parent->color;
							pDB->parent->color = BLACK;
							sibling->right->color = BLACK;
							if (IsRightChild(sibling))
								RotationLeft(sibling);
							else
								RotationRight(sibling);
						}
					}
				}
			}
		}
	}
}
tNode* FindeMaxData(tNode* pNode)
{
	if (pNode)
	{
		while (!isLeaf(pNode->right))
			pNode = pNode->right;
	}
	return pNode;
}

tNode* Sibling(tNode* pNode)
{
	if (pNode->parent)
	{
		if (IsRightChild(pNode))
			return pNode->parent->left;
		else
			return pNode->parent->right;
	}
	return NULL;
}