#include <stdio.h>

int Compare(int x, int y);

void BinarySearch(int list[], int n)
{
	int left = 0, right = n, middle;
	int search;
	printf("찾을 숫자를 입력하세요 : ");
	scanf_s("%d", &search);
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (Compare(list[middle], search))
		{
		case -1:
			//search가 크다. (오른쪽에 있다)
			left = middle + 1;
			break;
		case 0:
			printf("이진 검색으로 찾은 %d의 색인 : %d\n ", search, middle + 1);
			return;
			break;
		case 1:
			//search가 작다. (왼쪽에 있다.)
			right = middle - 1;
			break;
		}
	}
	printf("이진 검색 결과 %d의 색인 검색 불가\n", search);
}
int Compare(int x, int y)
{
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}