#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int t, n, m;
	int i, j, k;
	int max;
	int arr[100];

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		max = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
			if (arr[j] > max)
			{
				max = arr[j];
			}
		}

		for (j = 0; j < n; j++)
		{
			for (k = max; k >= 1; k--)
			{

			}
		}
	}

	return 0;
}