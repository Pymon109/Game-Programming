#include <stdio.h>

void swap(int* x, int* y);

// ���� ���� �˰���
// n���� ����
//i�� ��ȸ° i~n �� �ּڰ� Ž�� �� i��°�� ��ȯ

void SelectionSorting(int list[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (list[i] > list[j])
				swap(list+i, list+j);

	printf("���� ���� : ");
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