#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[1000000];

int main()
{
	int n;
	int i, j;
	int temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	for (i = 0; i < n; i++)	// 버블정렬
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}