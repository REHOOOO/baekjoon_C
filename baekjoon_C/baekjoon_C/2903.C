#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int num = 2;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		num = num + num - 1;
	}

	num = num * num;

	printf("%d", num);

	return 0;
}