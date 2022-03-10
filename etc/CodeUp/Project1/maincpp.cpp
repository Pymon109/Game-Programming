#include <stdio.h>
int main()
{
	int h, b, c, s;
	scanf_s("%d %d %d %d", &h, &b, &c, &s);
	long long int cal = h * b * c * s;
	//long double result = long long int(h * b * c * s) / (long double)(8*1024*1024);
	printf("%.1lf MB", cal / 8388608);
}