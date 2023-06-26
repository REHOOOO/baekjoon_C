#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	int i, j;
	int num[100];
	int temp;
	int t;

	scanf("%d %d", &n, &m);

	for (t = 0; t < n; t++)
	{
		num[t] = t + 1;
	}

	for (t = 0; t < m; t++)
	{
		scanf("%d %d", &i, &j);
		temp = num[i - 1];
		num[i - 1] = num[j - 1];
		num[j - 1] = temp;
	}

	for (t = 0; t < n; t++)
	{
		printf("%d ", num[t]);
	}

	return 0;
}