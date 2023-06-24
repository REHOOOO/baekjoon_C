#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int a, i;
	int num = 0;

	scanf("%d", &a);
	
	for (i = 1; i <= a; i++)
	{
		num = num + i;
	}

	printf("%d", num);

	return 0;
}