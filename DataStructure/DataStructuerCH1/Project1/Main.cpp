//2021.07.28

#include <stdio.h>
#include <random>
#include <time.h>

void ShuffleList(int list[], int *n);

void SelectionSorting(int list[], int n);
void BinarySearch(int list[], int n);
void Permutations(int list[], int i, int n);

void main() 
{
	int n = 0;
	int seed[100];

	ShuffleList(seed, &n);

	SelectionSorting(seed, n);
	BinarySearch(seed, n);
	printf("순열 출력\n");
	Permutations(seed, 0, n);
}

void ShuffleList(int list[], int *n)
{
	for (int i = 0; i < 100; i++)
		list[i] = i;
	printf("0~99사이 n개 수열 랜덤 생성 n : ");
	scanf_s("%d", n);

	//랜덤 수열 생성
	srand(time(NULL));
	for (int i = 0; i < *n; i++)
	{
		int input = rand() % 100;
		int temp = list[i];
		list[i] = list[input];
		list[input] = temp;
	}
	printf("랜덤 수열 : ");
	for (int i = 0; i < *n; i++)
		printf("%d ", list[i]);
	printf("\n");
}

