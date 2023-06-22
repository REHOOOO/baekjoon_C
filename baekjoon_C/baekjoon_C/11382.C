#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%.lf", a + b + c);

	return 0;
}