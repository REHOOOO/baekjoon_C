#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int solution[5000] = { 0, };

int main()
{
	int n;
	int i, j, k;
	double min = 3000000000;
	int result[3] = { 0, };
	int temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &solution[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (k == i || k == j)
				{
					continue;
				}
				else if (min > abs(solution[i] + solution[j] + solution[k]))
				{
					min = abs(solution[i] + solution[j] + solution[k]);
					result[0] = solution[i];
					result[1] = solution[j];
					result[2] = solution[k];
				}
			}
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<2-i;j++)
		{
			if(result[j]>result[j+1])
			{
				temp = result[j];
				result[j] = result[j+1];
				result[j+1] = temp;
			}
		}
	}

	printf("%d %d %d", result[0], result[1], result[2]);

	return 0;
}