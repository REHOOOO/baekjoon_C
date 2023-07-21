#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[1000000];

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void qsort(int start, int end)
{
	if (start >= end)
	{
		return;
	}
	
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)
	{
		while (i <= end && num[i] <= num[key])
		{
			i++;
		}
		while (j > start && num[j] >= num[key])
		{
			j--;
		}

		if (i > j)
		{
			swap(&num[key], &num[j]);
		}
		else
		{
			swap(&num[i], &num[j]);
		}

		qsort(start, j - 1);
		qsort(j + 1, end);
	}
}


int main()
{
	int n;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	qsort(0, n - 1);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}