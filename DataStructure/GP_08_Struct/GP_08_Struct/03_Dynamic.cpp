#include <stdio.h>
#include <stdlib.h>

void DynamicAllocateMain()
{
	int* pData = (int*)malloc(sizeof(int));

	*pData = 10;
	printf("pData[%d] : %d\n", pData, *pData);
	free(pData);
}

void DynamicAllocateArrayMain()
{
	int nSize;
	printf("Array size : ");
	scanf_s("%d", &nSize);
	int* pData = (int*)malloc(sizeof(int) * nSize);
	for (int i = 0; i < nSize; i++)
	{
		pData[i] = i * 10;
		printf("pData[%d] : %d\n", i, pData[i]);
	}
	free(pData);
}