#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i, j;

	scanf("%d", &n);

	for(i = 0; i < (n * 2 - 1); i++)
	{
		if (i < n)
		{
			for (j = 0; j < n - (i + 1); j++)
			{
				printf(" ");
			}
			for (j = 0; j < ((i + 1) * 2 - 1); j++)
			{
				printf("*");
			}
		}
		else
		{
			for (j = 0; j < i - n + 1; j++)
			{
				printf(" ");
			}
			for (j = 0; j < (n * 2 - 1) - ((i + 1 - n) * 2); j++)
			{
				printf("*");
			}
		}

		printf("\n");
	}

	return 0;
}