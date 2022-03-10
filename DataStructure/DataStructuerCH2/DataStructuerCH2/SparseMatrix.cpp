//희소 행렬
//0이 많이 포함된 행렬이 희소 행렬
//희소 행렬의 경우 이차원 배열로 저장시 공간의 낭비
//구조체로 구현
#include <stdio.h>
#include <random>
#include <time.h>

#define MAX_DEGREE 101

struct sMatrix
{
	int row, col, value;
};
sMatrix terms[MAX_DEGREE];

void SparseMatrixMain()
{
	srand(time(NULL));
}

void RandomCreate()
{

}