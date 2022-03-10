#include <stdio.h>

void swap2(int* x, int* y);

void Permutations(int list[], int i, int n)
{
	if (i == n)
	{
		printf("{ ");
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
		printf("}\n");
	}

	//list[i] ~[n] 까지의 순열 출력
	for (int j = i; j < n; j++)
	{
		swap2(&list[i], &list[j]);
		Permutations(list, i + 1, n);
		swap2(&list[i], &list[j]);
	}
}

void swap2(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}