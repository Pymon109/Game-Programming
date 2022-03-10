#include <stdio.h>
#include <string.h>

union Matrix4x4
{
	struct
	{
		float _11, _12, _13, _14;
		float _21, _22, _23, _24;
		float _31, _32, _33, _34;
		float _41, _42, _43, _44;
	};
	float m[4][4];
};
void UnionTestMain()
{
	Matrix4x4 mat;
	int nCount = 0;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			mat.m[y][x] = nCount;
			nCount++;
		}
	}
	printf("mat._11 : %f\n", mat._11);
	printf("mat._21 : %f\n", mat._21);
	printf("mat._31 : %f\n", mat._31);
	printf("mat._41 : %f\n", mat._41);
}