#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int solution[100000] = { 0, };

int main()
{
	int n;
	int i, j;
	int min = 1000000000;
	int result[2] = { 0, };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &solution[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (abs(solution[i] + solution[j]) == 0)
			{
				result[0] = solution[i];
				result[1] = solution[j];
				break;
			}
			else if (min > abs(solution[i] + solution[j]))
			{
				min = abs(solution[i] + solution[j]);
				result[0] = solution[i];
				result[1] = solution[j];
			}
		}
	}

	printf("%d %d", result[0], result[1]);
}