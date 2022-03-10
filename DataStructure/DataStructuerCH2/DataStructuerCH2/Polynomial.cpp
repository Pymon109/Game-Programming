#include <stdio.h>
#include <random>
#include <time.h>

#define MAX_DEGREE 101

struct polynomial
{
	float coef;
	int expo;
};
polynomial terms[MAX_DEGREE];
int avail = 0;	//terms의 길이

extern void swap(int* x, int* y);
int Compare(int x, int y);
void Padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD);
void Attach(float coef, int expo);
void Sortiing(int start, int finish);
void Swap(polynomial* x, polynomial* y);

void FitPolynomialMain()
{
	srand(time(NULL));
	int startA = 0, finishA, startB, finishB, input;
	printf("다항식 랜덤 생성.\n");
	printf("최대 지수 입력 : ");
	scanf_s("%d", &input);

	//A 생성
	for (int i = 0; i <= input; i++)
	{
		terms[i].expo = i;
		int coef = rand() % 101;
		coef = rand() % 2 == 0 ? coef * -1 : coef;
		terms[i].coef = coef;
	}
	for (int i = 0; i <= input; i++)
		swap(&terms[i].expo, &terms[rand() % input].expo);
	finishA = rand() % input + 1;
	Sortiing(startA, finishA);

	//B 생성
	startB = finishA + 1;
	for (int i = startB; i <= startB + input; i++)
	{
		terms[i].expo = i - startB;
		int coef = rand() % 101;
		coef = rand() % 2 == 0 ? coef * -1 : coef;
		terms[i].coef = coef;
	}
	for (int i = startB; i <= startB + input; i++)
		swap(&terms[i].expo, &terms[(rand() % input)+startB].expo);
	finishB = rand() % input + 1 + startB;
	Sortiing(startB, finishB);

	avail = finishB + 1;

	
	printf("다항식 A : ");
	for (int i = 0; i <= finishA; i++)
	{
		printf("%.fX^%d", terms[i].coef, terms[i].expo);
		if (i < finishA)
			printf(" + ");
	}
	printf("\n");
	printf("다항식 B : ");
	for (int i = startB; i <= finishB; i++)
	{
		printf("%.fX^%d", terms[i].coef, terms[i].expo);
		if (i < finishB)
			printf(" + ");
	}
	printf("\n");

	int startD, finishD;
	Padd(startA, finishA, startB, finishB, &startD, &finishD);

	printf("다항식 A+B = D : ");
	for (int i = startD; i <= finishD; i++)
	{
		printf("%.fX^%d", terms[i].coef, terms[i].expo);
		if (i < finishD)
			printf(" + ");
	}
	printf("\n");

}

void Padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
	float coef;
	*startD = avail;
	while (startA<=finishA && startB <= finishB)
	{
		switch (Compare(terms[startA].expo, terms[startB].expo))
		{
		case -1:	// a.expo < b.expo
			//a를 d에 추가 후 a 다음으로 넘기기
			Attach(terms[startA].coef, terms[startA].expo);
			startA++;
			break;
		case 0:	// a.expo = b.expo
			//더해주고 a,b 다음으로 넘기기
			Attach(terms[startA].coef + terms[startB].coef, terms[startA].expo);
			startA++;
			startB++;
			break;
		case 1:	// a.expo > b.expo
			//b를 d에 추가 후 b 다음으로 넘기기
			Attach(terms[startB].coef, terms[startB].expo);
			startB++;
			break;
		default:
			break;
		}
	}
	for (;startA <=finishA;startA++)
		Attach(terms[startA].coef, terms[startA].expo);
	for (; startB <= finishB; startB++)
		Attach(terms[startB].coef, terms[startB].expo);
	*finishD = avail - 1;
}

int Compare(int x, int y)
{
	if (x < y)
		return -1;
	else if (x == y)
		return 0;
	else
		return 1;
}

void Attach(float coef, int expo)
{
	terms[avail].coef = coef;
	terms[avail].expo = expo;
	avail += 1;
}

void Sortiing(int start, int finish)
{
	for (int i = start; i <= finish; i++)
	{
		for (int j = i; j <= finish; j++)
		{
			if (terms[i].expo > terms[j].expo)
				Swap(&terms[i], &terms[j]);
		}
	}
}

void Swap(polynomial *x, polynomial *y)
{
	polynomial temp;
	temp = *x;
	*x = *y;
	*y = temp;
}