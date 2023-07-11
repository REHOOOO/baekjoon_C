#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int m, n;
	int i, j;
	int total = 0;
	int min = 100000;
	int flag = 0;

	scanf("%d", &m);
	scanf("%d", &n);

	for (i = m; i <= n; i++)
	{
		flag = 0;

		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}

		if (i != 1)
		{
			if (flag == 0)
			{
				total = total + i;
				if (i < min)
				{
					min = i;
				}
			}
		}
	}

	if (total == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n", total);
		printf("%d", min);
	}

	return 0;
}