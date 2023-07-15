#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x[3];
	int y[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	if (x[0] == x[1])
	{
		printf("%d ", x[2]);
	}
	else if (x[0] == x[2])
	{
		printf("%d ", x[1]);
	}
	else if (x[1] == x[2])
	{
		printf("%d ", x[0]);
	}

	if (y[0] == y[1])
	{
		printf("%d", y[2]);
	}
	else if (y[0] == y[2])
	{
		printf("%d", y[1]);
	}
	else if (y[1] == y[2])
	{
		printf("%d", y[0]);
	}

	return 0;
}