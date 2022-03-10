#include <stdio.h>
int main(void)
{
	int _right;
	int _left;
	char _operator;

	printf("수식을 입력하세요 : ");
	scanf_s("%d %c %d", &_right, &_operator, 1, &_left);

	switch (_operator)
	{
		case '+':
			printf("%d + %d = %d", _right, _left, _right + _left);
			break;
		case '-':
			printf("%d - %d = %d", _right, _left, _right - _left);
			break;
		case '*':
			printf("%d * %d = %d", _right, _left, _right * _left);
			break;
		case '/':
			printf("%d / %d = %f", _right, _left, (float)_right / (float)_left);
			break;
		default:
			printf("연산자 입력 오류. \n");
	}
}