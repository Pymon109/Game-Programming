#include <stdio.h>

int Compare(int x, int y);

void BinarySearch(int list[], int n)
{
	int left = 0, right = n, middle;
	int search;
	printf("ã�� ���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &search);
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (Compare(list[middle], search))
		{
		case -1:
			//search�� ũ��. (�����ʿ� �ִ�)
			left = middle + 1;
			break;
		case 0:
			printf("���� �˻����� ã�� %d�� ���� : %d\n ", search, middle + 1);
			return;
			break;
		case 1:
			//search�� �۴�. (���ʿ� �ִ�.)
			right = middle - 1;
			break;
		}
	}
	printf("���� �˻� ��� %d�� ���� �˻� �Ұ�\n", search);
}
int Compare(int x, int y)
{
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}