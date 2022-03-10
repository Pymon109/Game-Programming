#include <stdio.h>

void swap(int* x, int* y);

// 선택 정렬 알고리즘
// n개의 수열
//i번 순회째 i~n 중 최솟값 탐색 후 i번째와 교환

void SelectionSorting(int list[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (list[i] > list[j])
				swap(list+i, list+j);

	printf("선택 정렬 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}