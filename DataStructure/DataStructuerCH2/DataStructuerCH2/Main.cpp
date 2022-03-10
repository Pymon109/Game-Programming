

void swap(int* x, int* y);

void FitPolynomialMain();

void main()
{
	FitPolynomialMain();
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}