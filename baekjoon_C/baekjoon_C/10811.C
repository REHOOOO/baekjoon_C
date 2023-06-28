#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[100];
	int n, m;
	int i, j;
	int k, l;
	int temp;

	scanf("%d %d", &n, &m);

	for (k = 0; k < n; k++)
	{
		num[k] = k + 1;
	}

	for (k = 0; k < m; k++)
	{
		scanf("%d %d", &i, &j);
		for (l = 0; l < ((j - i) / 2) + 1; l++)
		{
			temp = num[i - 1 + l];
			num[i - 1 + l] = num[j - 1 - l];
			num[j - 1 - l] = temp;
		}
	}

	for (k = 0; k < n; k++)
	{
		printf("%d ", num[k]);
	}

	return 0;
}