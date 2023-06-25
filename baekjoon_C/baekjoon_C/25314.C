#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n;
	int i = 0;

	scanf("%d", &n);

	for (i = 0; i < n/4; i++)
	{
		printf("long ");
	}

	printf("int");

	return 0;
}